#include <iostream>
#include <raylib.h>
#include "grid.hpp"
#include "simulation.hpp"

int main() {
    Color GREY = { 255,255,255,255 };
    const int WINDOW_WIDTH = 750;
    const int WINDOW_HEIGHT = 750;
    const int CELL_SIZE = 25;

    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Game of Life");
    SetTargetFPS(12);

    Simulation simulation{ WINDOW_WIDTH,WINDOW_HEIGHT,CELL_SIZE };

    while (!WindowShouldClose()) {
        // Obsługa zdarzeń
        if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
            Vector2 mousePosition = GetMousePosition();
            int row = mousePosition.y / CELL_SIZE;
            int col = mousePosition.x / CELL_SIZE;
            simulation.ToggleCell(row, col);

        }

        if (IsKeyPressed(KEY_C)) {
            simulation.ClearGrid();
        }

        if (IsKeyPressed(KEY_R)) {
            simulation.CreateRandomState();
        }

        BeginDrawing();
        ClearBackground(GREY);
        simulation.Draw();
        EndDrawing();
    }

    CloseWindow();
    return 0;

}