#include "renderer.hpp"
#include "raylib.h"

// Constructor: initializes the Renderer with the simulation reference
Renderer::Renderer(Simulation& sim) : simulation(sim) {}

// Draws the entire grid and cells
void Renderer::Draw() {
    // Variable to keep track of the current row index
    int rowIdx = 0;
    
    // Loop through each row in the grid
    for (int row = 0; row < simulation.GetGrid().GetRows(); ++row) {
        // Variable to keep track of the current column index
        int colIdx = 0;

        // Loop through each column in the grid
        for (int col = 0; col < simulation.GetGrid().GetCols(); ++col) {
            // Colors for cell states
            constexpr Color aliveColor{0, 0, 255, 255}; // Blue for alive cells
            constexpr Color deadColor{0, 0, 0, 255};   // Black for dead cells

            // Check the current cell state and choose the corresponding color
            const Color& color = (simulation.GetGrid().GetValue(row, col) == CellState::ALIVE) ? aliveColor : deadColor;

            // Draw a rectangle for each cell at the appropriate position in the window
            // The position is determined by multiplying the cell's index by its size
            // The size of the cell is also used to adjust the width and height of the rectangle
            // Subtracting 1 from the size to ensure there is a slight gap between cells
            DrawRectangle(colIdx * simulation.GetGrid().GetCellSize(), 
                          rowIdx * simulation.GetGrid().GetCellSize(), 
                          simulation.GetGrid().GetCellSize() - 1,  // Keep small gaps between cells
                          simulation.GetGrid().GetCellSize() - 1, 
                          color);

            // Increment the column index for the next cell in the row
            colIdx++;
        }
        
        // Increment the row index for the next row in the grid
        rowIdx++;
    }
}
