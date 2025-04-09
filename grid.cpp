#include "grid.hpp"
#include <raylib.h>

void Grid::Draw()
{
    for(int row = 0; row < rows; row++) {
        for(int col = 0; col < cols; col++) {
            Color color = cells[row][col] ? Color{0,0,255,255} : Color{0,0,0,255};
            DrawRectangle(col * cellSize, row * cellSize, cellSize-1, cellSize-1, color);
        }
    }
}

void Grid::SetValue(int row, int column, int value){
    if (IsWithinBounds(row, column)) {
        cells[row][column] = value;
    }
}

int Grid::GetValue(int row, int col) {
    if (IsWithinBounds(row, col)) {
        return cells[row][col]
    }
    return 0;
}

bool Grid::IsWithinBounds(int row, int col) {
    if (row >= 0 && row < rows && col >= 0 && col < cols) {
        return true;
    }
    return false;
}