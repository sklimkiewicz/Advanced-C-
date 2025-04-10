#include "simulation.hpp"

void Simulation::Draw() {
	grid.Draw();
}

void Simulation::SetCellValue(int row, int col, int value) {
	grid.SetValue(row, col, value);
}

void Simulation::ClearGrid() {
	grid.Clear();
}

void Simulatio::CreateRandomState() {
	grid.FillRandom();
}

void Simulation::ToggleCell(int row, int col) {
	grid.ToggleCell(row, col);
}

