#pragma once
#include "grid.hpp"

class Simulation {
public:
	Simulation(int width, int height, int cellSize) :
		grid(width, height, cellSize),
		run(false) {}

	void Draw();
	void SetCellValue(int row, int col, int value);
	void ClearGrid();
	void CreateRandomState();
	void ToggleCell(int row, int col);

private:
	Grid grid;
	bool run;
};
