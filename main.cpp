#include <iostream>
#include <raylib.h>
#include <stdexcept>
#include "grid.hpp"
#include "simulation.hpp"
using namespace std;

int main() {
    try {
        // Constants and initialization
        const Color GREY = { 255,255,255,255 };
        const int WINDOW_WIDTH = 750;
        const int WINDOW_HEIGHT = 750;
        const int CELL_SIZE = 25;//750/25=30 cells in each row and column
        int FPS = 12;//12 times per second at most

        // Initialize Raylib window
        InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Game of Life");
        SetTargetFPS(FPS);

        // Create simulation
        Simulation simulation{ WINDOW_WIDTH,WINDOW_HEIGHT,CELL_SIZE };

        // Main game loop
        while (!WindowShouldClose()) {
            try {
                // Event handling
                if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
                    Vector2 mousePosition = GetMousePosition();
                    int row = mousePosition.y / CELL_SIZE;
                    int col = mousePosition.x / CELL_SIZE;
                    simulation.ToggleCell(row, col);

                }

                // Key handling
                if (IsKeyPressed(KEY_ENTER)) {
                    simulation.Start();
                    SetWindowTitle("Game of Life is running...");
                }
                else if (IsKeyPressed(KEY_SPACE)) {
                    simulation.Stop();
                    SetWindowTitle("Game of Life has stopped.");
                }
                else if (IsKeyPressed(KEY_F)) {
                    FPS += 2;//increase the speed of the simulation
                    SetTargetFPS(FPS);
                }
                else if (IsKeyPressed(KEY_S)) {
                    if (FPS > 5) {
                        FPS -= 2;//decresase the speed
                        SetTargetFPS(FPS);
                    }
                }

                else if (IsKeyPressed(KEY_C)) {
                    simulation.ClearGrid();
                }

                else if (IsKeyPressed(KEY_R)) {
                    simulation.CreateRandomState();
                }

                // Save/Load functionality with error handling
                else if (IsKeyPressed(KEY_L)) {
                    try {
                        const std::string filename = "game_state.txt";
                        if (simulation.LoadFromFile(filename)) {
                            SetWindowTitle("Game state loaded successfully");
                        }
                        else {
                            SetWindowTitle("ERROR: Failed to load game state");
                        }
                    }
                    catch (const std::exception& e) {
                        SetWindowTitle("ERROR: Failed to load game state");
                        std::cerr << "Load error: " << e.what() << std::endl;
                    }
                }
                else if (IsKeyPressed(KEY_O)) { // 'O' for save
                    try {
                        const std::string filename = "game_state.txt";
                        if (simulation.SaveToFile(filename)) {
                            SetWindowTitle("Game state saved successfully");
                        }
                        else {
                            SetWindowTitle("ERROR: Failed to save game state");
                        }
                    }
                    catch (const std::exception& e) {
                        SetWindowTitle("ERROR: Failed to save game state");
                        std::cerr << "Save error: " << e.what() << std::endl;
                    }
                }

                // state update
                simulation.Update();

                // drawing objects
                BeginDrawing();
                ClearBackground(GREY);
                simulation.Draw();
                EndDrawing();
            }
            catch (const std::exception& e) {
                // Handle non-fatal errors that can occur during the loop
                std::cerr << "Error in main loop: " << e.what() << std::endl;
                SetWindowTitle("An error occurred in the game loop");
            }
            catch (...) {
                // Catch any other unexpected errors
                std::cerr << "Unknown error in main loop" << std::endl;
                SetWindowTitle("An unknown error occurred");
            }

        }

        CloseWindow();
        return 0;
    }
    catch (const std::exception& e) {
        // Handle fatal errors during initialization
        std::cerr << "Critical error: " << e.what() << std::endl;
        return 1;
    }
    catch (...) {
        // Catch any other unexpected fatal errors
        std::cerr << "Unknown critical error occurred" << std::endl;
        return 1;
    }


}