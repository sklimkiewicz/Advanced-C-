#pragma once
#include <vector>
#include <string>
#include <iostream>

enum class CellState
{
    DEAD = 0,
    ALIVE = 1
};

//forward declaration of classes
class Cell;
class Row; 

//cell class
class Cell{
    private: 
        CellState state;
    public:
        Cell():state(CellState::DEAD){};
        void SetState(CellState newState) { state = newState; };
        CellState GetState() const{ return state; };
        void ToggleState() { state = (state == CellState::ALIVE) ? CellState::DEAD : CellState::ALIVE; };
        bool IsAlive() const { return state == CellState::ALIVE; };
    };


//Row class represents a row of cells
class Row{
    private:
        std::vector<Cell> cells;
    public:
        Row(int size):cells(size){};
        Cell& operator[](int index){return cells[index];};
        const Cell& operator[](int index) const { return cells[index]; }
        auto begin() { return cells.begin(); };
        auto end() { return cells.end(); };
        auto begin() const { return cells.begin(); };
        auto end() const { return cells.end(); };
        size_t Size() const { return cells.size(); };
    };

class Grid
{ 
    public:
        Grid(int width, int height, int cellSize): 
            rows(height/cellSize), 
            cols(width/cellSize), 
            cellSize(cellSize), 
            grid(height/cellSize, Row(width/cellSize)) 
        {};
        
        //file operations
        bool SaveToFile(const std::string& filename) const;
        bool LoadFromFile(const std::string& filename);


        void Draw();
        void SetValue(int row, int column, CellState state);
        CellState GetValue(int row, int col) const;
        bool IsWithinBounds(int row, int col) const;
        int GetRows() const { return rows; }
        int GetCols() const { return cols; }
        void FillRandom();
        void Clear();
        void ToggleCell(int row, int col);

        //iterator  access
        Row& operator[](int index) { return grid[index]; }
        const Row& operator[](int index) const { return grid[index]; }
        auto begin() { return grid.begin(); }
        auto end() { return grid.end(); }
        auto begin() const { return grid.begin(); }
        auto end() const { return grid.end(); }

    private:
        const int rows; //number of rows in the grid
        const int cols; //number of columns in the grid 
        const int cellSize; //size of each cell in pixels
        std::vector<Row> grid; //2d grid of cells
};