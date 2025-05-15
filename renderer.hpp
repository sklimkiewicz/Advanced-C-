#ifndef RENDERER_HPP
#define RENDERER_HPP

// Include the necessary header for the simulation and raylib library
#include "simulation.hpp"
#include <raylib.h>

// Renderer class is responsible for drawing the simulation grid and cells
class Renderer {
public:
    // Constructor: initializes the Renderer with a reference to the Simulation object
    Renderer(Simulation& sim);
    
    // Method: draws the entire grid based on the current state of cells
    void Draw();
    
private:
    // Reference to the Simulation object to access the grid and its state
    Simulation& simulation;
};

#endif // RENDERER_HPP
