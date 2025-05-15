#include "simulation.hpp"
#include <iostream>
#include <raylib.h>

// Constructor: Initializes the simulation with grid dimensions and cell size
Simulation::Simulation(int width, int height, int cellSize)
    : grid(width, height, cellSize), run(false) {}  // Passes the necessary arguments to the Grid constructor

// Update method: Updates the grid based on whether the simulation is running
void Simulation::Update() {
    if (run) {
        grid.Update();  // Calls the Update method of the Grid class if the simulation is running
    }
}

// HandleInput method: Handles user input for controlling the simulation
void Simulation::HandleInput() {
    // Toggle the simulation state (run/pause) when the Enter key is pressed
    if (IsKeyPressed(KEY_ENTER)) {
        run = !run;  // If the Enter key is pressed, toggle the run flag
    }

    // Handle toggling of individual cells with a mouse click
    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
        int mouseX = GetMouseX();  // Get the current mouse X position
        int mouseY = GetMouseY();  // Get the current mouse Y position
        int x = mouseX / grid.GetCellSize();  // Calculate the cell's X index based on mouse position
        int y = mouseY / grid.GetCellSize();  // Calculate the cell's Y index based on mouse position
        ToggleCell(x, y);  // Toggle the state of the cell at (x, y)
    }
}

// ToggleCell method: Switches the state (alive or dead) of a specific cell
void Simulation::ToggleCell(int x, int y) {
    grid.ToggleCell(x, y);  // Calls the ToggleCell method of the Grid class to change the state of the cell
}
