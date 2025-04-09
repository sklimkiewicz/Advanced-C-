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