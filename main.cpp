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
    //losowe wypełnienie siatki
    grid.FillRandom();

    while(!WindowShouldClose()) {
               // Obsługa zdarzeń
               if(IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
                Vector2 mousePosition = GetMousePosition();
                int row = mousePosition.y / CELL_SIZE;
                int col = mousePosition.x / CELL_SIZE;
                grid.ToggleCell(row, col);
    
    }
    
    if(IsKeyPressed(KEY_C)) {
        grid.Clear();
    }
    
    if(IsKeyPressed(KEY_R)) {
        grid.FillRandom();
    }
    
    BeginDrawing();
    ClearBackground(GREY);
    grid.Draw();
    EndDrawing();
}

CloseWindow();
return 0;

}