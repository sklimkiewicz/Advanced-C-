#include "simulation.hpp"
#include <utility>
#include <vector>

void Simulation::Draw() {
	grid.Draw();
}

void Simulation::SetCellValue(int row, int col, CellState state) {
	grid.SetValue(row, col, state);
}

int Simulation::CountLiveNeighbors(int row, int col) cnst
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
        if (grid.GetValue(neighborRow, neighborCol) == CellState::ALIVE) {
            liveNeighbours++;
        }
    }
    return liveNeighbours;
}

void Simulation::Update()
{
    if(IsRunning()) {
        // Calculate next generation based on Conway's Game of Life rules
        for(int row = 0; row < grid.GetRows(); row++) {
            for(int col = 0; col < grid.GetCols(); col++) {
                int liveNeighbors = CountLiveNeighbors(row, col); 
                CellState currentState = grid.GetValue(row, col);

                if(currentState == CellState::ALIVE) {
                    // regula 1 i 3: komorka umiera z powodu osamotnienia lub przeludnienia
                    if(liveNeighbors < 2 || liveNeighbors > 3) {
                        tempGrid.SetValue(row, col, CellState::DEAD);
                    } else {
                        // regula 2: komorka przeżywa
                        tempGrid.SetValue(row, col, CellState::ALIVE);
                    }
                } else {
                    // regula 4: martwa komorka ożywa
                    if(liveNeighbors == 3) {
                        tempGrid.SetValue(row, col, CellState::ALIVE);
                    } else {
                        tempGrid.SetValue(row, col, CellState::DEAD);
                    }
                }
            }
        }
        // Update the grid with the new generation
        grid = tempGrid; 
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
    if (!IsRunning()) {
        grid.ToggleCell(row, col);
    }
}

bool Simulation::SaveToFile(const std::string& filename) const {
    return grid.SaveToFile(filename);
}

bool Simulation::LoadFromFile(const std::string& filename) {
    return grid.LoadFromFile(filename);
}
