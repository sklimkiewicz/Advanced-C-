#include <iostream>
#include <raylib.h>
#include <stdexcept>
#include "simulation.hpp"
#include "renderer.hpp"
using namespace std;

int main() {
   
        // Constants and initialization
        const Color GREY = { 255,255,255,255 };
        const int WINDOW_WIDTH = 750;
        const int WINDOW_HEIGHT = 750;
        const int CELL_SIZE = 25;//750/25=30 cells in each row and column
        int FPS = 12;//12 times per second at most

        // Calculate the number of cells in the grid (rows and columns)
        const int width = WINDOW_WIDTH / CELL_SIZE;  // Number of cells per row
        const int height = WINDOW_HEIGHT / CELL_SIZE; // Number of cells per column

        // Initialize Raylib window
        InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Game of Life");
        SetTargetFPS(FPS);

        // Create the simulation with the calculated grid dimensions
        Simulation simulation{ width,height,CELL_SIZE };
        Renderer renderer(simulation);

          // Fill the grid with random cell states (alive or dead)
        simulation.GetGrid().FillRandom();

        // Set the frame rate for the game (how many times per second the game updates)
        SetTargetFPS(10);  // Game speed

        // Main game loop
        

    // Main game loop
    while (!WindowShouldClose()) {
        // Handle player input (e.g., toggling cells or starting/stopping the simulation)
        simulation.HandleInput();

        // Update the grid based on the current state and rules of the Game of Life
        simulation.Update();

        // Begin drawing the next frame
        BeginDrawing();
        
        // Clear the screen (set the background to black)
        ClearBackground(BLACK);

        // Draw the grid and cells to the screen
        renderer.Draw();

        // End drawing the frame
        EndDrawing();
    }

    // Close the window and OpenGL context when the game is over
    CloseWindow();
    return 0;
}

