#include "grid.hpp"
#include <raylib.h>
#include <fstream>
#include <stdexcept>

void Grid::Draw()
{
    int rowIdx = 0;
    for(const auto& row : grid) {
        int colIdx = 0;
        for( const auto& cell : row)
 {          constexpr Color aliveColor{0,0,255,255};
            constexpr Color deadColor{0,0,0,255};
            const Color& color = cell.IsAlive() ? aliveColor : deadColor;
            DrawRectangle(colIdx * cellSize, rowIdx * cellSize, cellSize-1, cellSize-1, color);
            colIdx++;
        }
        rowIdx++;
    }
}

void Grid::SetValue(int row, int col, CellState state){
    if (IsWithinBounds(row, col)) {
        grid[row][col].SetState(state);
    }
}

CellState Grid::GetValue(int row, int col) const{
    if (IsWithinBounds(row, col)) {
        return grid[row][col].GetState();
    }
    return CellState::DEAD; // default to DEAD for out-of-bounds
}

bool Grid::IsWithinBounds(int row, int col)const noexcept{
    return (row >= 0 && row < rows && col >= 0 && col < cols);
}

void Grid::FillRandom()
{
    for(int row = 0; row < rows; row++) {
        for (int col = 0; col < cols; col++) {
            int randomValue = GetRandomValue(0, 4); // 20% szansa na żywą komórkę
            grid[row][col].SetState (randomValue == 4 ? CellState::ALIVE : CellState::DEAD);

        }
    }
}

void Grid::Clear()
{
    for(auto& row : grid) {
        for(auto& cell : row) 
 {
            cell.SetState(CellState::DEAD); // all cells are dead
        }
    }
}

void Grid::ToggleCell(int row, int col)
{
    if(IsWithinBounds(row, col)) {
        grid[row][col].ToggleState();
    }
}

bool Grid::SaveToFile(const std::string& filename) const
{
    try {
        std::ofstream file(filename);
        if (!file.is_open()) {
            throw std::runtime_error("Could not open file for writing");
        }
        
        // write grid dimensions
        file << rows << " " << cols << std::endl;
        
        // write cell states
        for(const auto& row : grid) {
            for(const auto& cell : row) {
                file << (cell.IsAlive() ? "1" : "0");
            }
            file << std::endl;
        }
        
        file.close();
        return true;
    }
    catch(const std::exception& e) {
        std::cerr << "Error saving grid: " << e.what() << std::endl;
        return false;
    }
}

bool Grid::LoadFromFile(const std::string& filename)
{
    try {
        std::ifstream file(filename);
        if (!file.is_open()) {
            throw std::runtime_error("Could not open file for reading");
        }
        
        // read grid dimensions
        int fileRows, fileCols;
        file >> fileRows >> fileCols;
        
        // verify dimensions match
        if (fileRows != rows || fileCols != cols) {
            throw std::runtime_error("Grid dimensions in file do not match current grid");
        }
        
        // skip newline
        file.ignore();
        
        // read cell states
        for(int r = 0; r < rows; r++) {
            std::string line;
            std::getline(file, line);
            
            if (line.length() < static_cast<size_t>(cols)) {
                throw std::runtime_error("Incomplete data in file");
            }
            
            for(int c = 0; c < cols; c++) {
                grid[r][c].SetState(line[c] == '1' ? CellState::ALIVE : CellState::DEAD);
            }
        }
        
        file.close();
        return true;
    }
    catch(const std::exception& e) {
        std::cerr << "Error loading grid: " << e.what() << std::endl;
        return false;
    }
}
