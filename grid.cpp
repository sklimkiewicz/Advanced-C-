#include "grid.hpp"
#include <raylib.h>
#include <fstream>
#include <stdexcept>

Grid::Grid(int width, int height, int cellSize)
    : rows(width), cols(height), cellSize(cellSize), grid(width, std::vector<Cell>(height)) {}

void Grid::SetValue(int row, int col, CellState state){
    if (IsWithinBounds(row, col)) {
        grid[row][col].SetState(state);
    }
}

CellState Grid::GetValue(int row, int col) const{
    if (IsWithinBounds(row, col)) {
        return grid[row][col].GetState();
    }
    return CellState::DEAD; // default to DEAD for out-of-bounds
}

bool Grid::IsWithinBounds(int row, int col)const noexcept{
    return (row >= 0 && row < rows && col >= 0 && col < cols);
}

// Count the number of living neighbors of a given cell at position (row, col)
int Grid::CountNeighbors(int row, int col) const {
    int count = 0;

    // Iterate over all neighboring cells (including diagonals)
    for (int i = -1; i <= 1; ++i) {
        for (int j = -1; j <= 1; ++j) {
            // Skip the cell itself (i == 0 and j == 0)
            if (i == 0 && j == 0) continue;

            int neighborRow = row + i;
            int neighborCol = col + j;

            // Check if the neighbor is within bounds
            if (neighborRow >= 0 && neighborRow < rows && neighborCol >= 0 && neighborCol < cols) {
                // Count the living neighbors
                if (grid[neighborRow][neighborCol].GetState() == CellState::ALIVE) {
                    count++;
                }
            }
        }
    }

    return count; // Return the total number of living neighbors
}

// Update the grid based on the Game of Life rules
void Grid::Update() {
    tempGrid = grid; // Copy the current grid to a temporary grid for calculations

    // Iterate through each cell in the grid
    for (size_t row = 0; row < rows; ++row) {
        for (size_t col = 0; col < cols; ++col) {
            int neighbors = CountNeighbors(row, col); // Get the number of living neighbors for the current cell

            // Apply the Game of Life rules to each cell
            if (grid[row][col].GetState() == CellState::ALIVE) {
                // Any live cell with fewer than two or more than three neighbors dies
                if (neighbors < 2 || neighbors > 3) {
                    tempGrid[row][col].SetState(CellState::DEAD);
                }
            } else {
                // Any dead cell with exactly three neighbors becomes alive
                if (neighbors == 3) {
                    tempGrid[row][col].SetState(CellState::ALIVE);
                }
            }
        }
    }

    grid = tempGrid; // Update the grid with the new state after all calculations
}



void Grid::FillRandom()
{
    for(int row = 0; row < rows; row++) {
        for (int col = 0; col < cols; col++) {
            int randomValue = GetRandomValue(0, 4); // 20% szansa na żywą komórkę
            grid[row][col].SetState (randomValue == 4 ? CellState::ALIVE : CellState::DEAD);

        }
    }
}



// Toggle the state of a cell between alive and dead at a specific position (x, y)
void Grid::ToggleCell(int x, int y) {
    // Ensure the x and y coordinates are within bounds
    if (x >= 0 && x < rows && y >= 0 && y < cols) {
        CellState currentState = grid[x][y].GetState(); // Get the current state of the cell
        // Toggle the state: if it's alive, set it to dead; if it's dead, set it to alive
        grid[x][y].SetState(currentState == CellState::ALIVE ? CellState::DEAD : CellState::ALIVE);
    }
}


