#pragma once
#include <vector>
#include <string>
#include <iostream>
#include <cstddef>

#ifndef GRID_HPP
#define GRID_HPP

// Enum to represent the possible states of a cell: DEAD or ALIVE
enum class CellState { DEAD, ALIVE };

//cell class
class Cell{
    private: 
        CellState state;
    public:
        Cell():state(CellState::DEAD){};
        void SetState(CellState newState) { state = newState; };
        CellState GetState() const{ return state; };
        //void ToggleState() { state = (state == CellState::ALIVE) ? CellState::DEAD : CellState::ALIVE; };
        //bool IsAlive() const { return state == CellState::ALIVE; };
    };



class Grid
{ 
    public:
    Grid(int width, int height, int cellSize);
        
        //void Draw();
        void SetValue(int row, int column, CellState state);
        CellState GetValue(int row, int col) const;
        bool IsWithinBounds(int row, int col) const noexcept;
        size_t GetRows() const { return rows; }
        size_t GetCols() const { return cols; }
        int GetCellSize() const { return cellSize; }// Get the size of each cell in the grid
        void FillRandom();
        //void Clear();
        
        void Update();// Update the grid according to the Game of Life rules
        void ToggleCell(int row, int col); // Toggle the state of a cell at position (x, y) between ALIVE and DEAD

    private:
        size_t rows, cols; // The number of rows and columns in the grid
        const int cellSize; //size of each cell in pixels
        std::vector<std::vector<Cell>> grid; // The grid itself, storing cells
        std::vector<std::vector<Cell>> tempGrid; // A temporary grid for calculating the next state of cells
        int CountNeighbors(int row, int col) const; // Count the number of ALIVE neighbors of a specific cell
};
#endif // GRID_HPP