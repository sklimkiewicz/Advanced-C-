#pragma once
#include "grid.hpp"
#include <string>

class Simulation {
public:
	Simulation(int width, int height, int cellSize) :
		grid(width, height, cellSize),
		run(false), tempGrid(width, height, cellSize) {}

	void Draw();
	void SetCellValue(int row, int col, CellState state);
	int CountLiveNeighbors(int row, int col) const;
	void Update();
	bool IsRunning() const { return run; }
	void Start() { run = true; }
	void Stop() { run = false; }
	void ClearGrid();
	void CreateRandomState();
	void ToggleCell(int row, int col);

	// File operations
	bool SaveToFile(const std::string& filename) const;
	bool LoadFromFile(const std::string& filename);


private:
	Grid grid; // Current state grid
	Grid tempGrid; // Temporary grid for calculating next state
	bool run; // Flag indicating if simulation is running
};
