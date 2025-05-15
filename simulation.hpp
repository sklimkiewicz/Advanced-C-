#ifndef SIMULATION_HPP
#define SIMULATION_HPP

#include "grid.hpp"

// The Simulation class represents the Game of Life simulation.
class Simulation {
public:
    // Constructor: Initializes the simulation with grid dimensions and cell size
    Simulation(int width, int height, int cellSize);
    
    // Updates the grid if the simulation is running
    void Update();

    // Handles user input to control the simulation (e.g., pause, toggle cells)
    void HandleInput();

    // Toggles the state (alive or dead) of a specific cell in the grid
    void ToggleCell(int x, int y);

    // Provides access to the grid object for other classes (like Renderer)
    Grid& GetGrid() { return grid; }

private:
    // The grid object representing the state of the Game of Life cells
    Grid grid;

    // Boolean flag indicating whether the simulation is running
    bool run;
};

#endif // SIMULATION_HPP
