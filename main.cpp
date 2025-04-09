#include <iostream>
#include <raylib.h>
#include "grid.hpp"

int main() {
    Color GREY = {255,255,255,255};
    const int WINDOW_WIDTH = 750;
    const int WINDOW_HEIGHT = 750;
    const int CELL_SIZE = 25;
    
    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Game of Life");
    SetTargetFPS(12);
    
    Grid grid{WINDOW_WIDTH, WINDOW_HEIGHT, CELL_SIZE};

    //Testowe ustawinia kilku komorek
    grid.SetValue(0, 0, 1);
    grid.SetValue(2, 1, 1);
    
    while(!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(GREY);
        grid.Draw();
        EndDrawing();
    }
    
    CloseWindow();
    return 0;
}