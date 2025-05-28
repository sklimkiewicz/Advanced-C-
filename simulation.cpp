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
    auto toggleRunState = [this]() {run=!run;};  // Lambda function to toggle the run state
    // Toggle the simulation state (run/pause) when the Enter key is pressed
    if (IsKeyPressed(KEY_ENTER)) {
        toggleRunState;  // Calls the lambda function to toggle the run state
    }

    auto handleMouseClick = [this](){ 
        Vector2 mousePos=GetMousePosition();  
        int x = static_cast<int>(mousePos.x / grid.GetCellSize());  // Calculate the cell's X index based on mouse position
        int y = static_cast<int>(mousePos.y / grid.GetCellSize());  // Calculate the cell's Y index based on mouse position
        ToggleCell(x, y);  // Toggle the state of the cell at (x, y) 
    };

    if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
        handleMouseClick();  // Calls the lambda function to handle mouse click
    }
    
}

// ToggleCell method: Switches the state (alive or dead) of a specific cell
void Simulation::ToggleCell(int x, int y) {
    grid.ToggleCell(x, y);  // Calls the ToggleCell method of the Grid class to change the state of the cell
}
