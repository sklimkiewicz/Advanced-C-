#include "simulation.hpp"
#include <utility>
#include <vector>

void Simulation::Draw() {
	grid.Draw();
}

void Simulation::SetCellValue(int row, int col, int value) {
	grid.SetValue(row, col, value);
}

int Simulation::CountLiveNeighbors(int row, int col)
{
    int liveNeighbours = 0;
    std::vector<std::pair<int,int>> neighborOffsets = {
        {-1,0}, // górny
        {1,0},  // dolny
        {0,-1}, // lewy
        {0,1},  // prawy
        {-1,-1}, // górny lewy
        {-1,1},  // górny prawy
        {1,-1},  // dolny lewy
        {1,1}    // dolny prawy
    };

    for(const auto& offset : neighborOffsets) {
        int neighborRow = (row + offset.first + grid.GetRows()) % grid.GetRows();
        int neighborCol = (col + offset.second + grid.GetCols()) % grid.GetCols();
        liveNeighbours += grid.GetValue(neighborRow, neighborCol);
    }
    return liveNeighbours;
}

void Simulation::Update()
{
    if(IsRunning()) {
        for(int row = 0; row < grid.GetRows(); row++) {
            for(int col = 0; col < grid.GetCols(); col++) {
                int liveNeighbors = CountLiveNeighbors(row, col); 
                int cellValue = grid.GetValue(row, col);
                
                if(cellValue == 1) {
                    // regula 1 i 3: komorka umiera z powodu osamotnienia lub przeludnienia
                    if(liveNeighbors < 2 || liveNeighbors > 3) {
                        tempGrid.SetValue(row, col, 0);
                    } else {
                        // regula 2: komorka przeżywa
                        tempGrid.SetValue(row, col, 1);
                    }
                } else {
                    // regula 4: martwa komorka ożywa
                    if(liveNeighbors == 3) {
                        tempGrid.SetValue(row, col, 1);
                    } else {
                        tempGrid.SetValue(row, col, 0);
                    }
                }
            }
        }
        grid = tempGrid; // aktualizacja siatki
    }
}


void Simulation::ClearGrid() {
	if(!IsRunning()) {
        grid.Clear();}
}

void Simulation::CreateRandomState() {
	if(!IsRunning()) {
        grid.FillRandom();
    }
}

void Simulation::ToggleCell(int row, int col) {
	grid.ToggleCell(row, col);
}
