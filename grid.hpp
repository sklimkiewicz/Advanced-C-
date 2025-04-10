#pragma once
#include <vector>

class Grid
{ 
    public:
        Grid(int width, int height, int cellSize): 
            rows(height/cellSize), 
            cols(width/cellSize), 
            cellSize(cellSize), 
            cells(rows, std::vector<int>(cols, 0)) 
        {};
        
        void Draw();
        void SetValue(int row, int column, int vaue);
        int GetValue(int row, int col);
        bool IsWithinBounds(int row, int col);
        int GetRows() { return rows; }
        int GetCols() { return cols; }
        void FillRandom();
        void Clear();
        void ToggleCell(int row, int col);

    private:
        int rows;
        int cols;
        int cellSize;
        std::vector<std::vector<int>> cells;
};