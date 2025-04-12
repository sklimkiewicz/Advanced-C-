#include <iostream>
#include <raylib.h>
#include "grid.hpp"
#include "simulation.hpp"
using namespace std;

int main() {
    Color GREY = { 255,255,255,255 };
    const int WINDOW_WIDTH = 750;
    const int WINDOW_HEIGHT = 750;
    const int CELL_SIZE = 25;//750/25=30 cells in each row and column
    int FPS = 12;//12 times per second at most

    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Game of Life");
    SetTargetFPS(FPS);

    Simulation simulation{ WINDOW_WIDTH,WINDOW_HEIGHT,CELL_SIZE };

    while (!WindowShouldClose()==false) {
        // Event handling
        if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
            Vector2 mousePosition = GetMousePosition();
            int row = mousePosition.y / CELL_SIZE;
            int col = mousePosition.x / CELL_SIZE;
            simulation.ToggleCell(row, col);

        }
        if(IsKeyPressed(KEY_ENTER)) {
            simulation.Start();
            SetWindowTitle("Game of Life is running...");
        }
        else if(IsKeyPressed(KEY_SPACE)) {
            simulation.Stop();
            SetWindowTitle("Game of Life has stopped.");
        }
        else if (IsKeyPressed(KEY_F)) {
            FPS += 2;//increase the speed of the simulation
            SetTarget(FPS);
        }
        else if (IsKeyPressed(KEY_S)) {
            if (FPS > 5) {
                FPS -= 2//decresase the speed
                    SetTargetFPS(FPS);
            }
        }

        else if (IsKeyPressed(KEY_C)) {
            simulation.ClearGrid();
        }

        else if (IsKeyPressed(KEY_R)) {
            simulation.CreateRandomState();
        }
        // state update
        simulation.Update();
                
        // drawing objects
        BeginDrawing();
        ClearBackground(GREY);
        simulation.Draw();
        EndDrawing();
    }

    CloseWindow();
    return 0;

}