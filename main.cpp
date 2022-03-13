#include <iostream>
#include <cmath>
#include <vector>
#include <string>

bool isPrime(int n);
void fillSide(std::vector<std::vector<int>>& grid, int x, int y, int xStep, int yStep, int c);

std::string to_string(std::vector<std::vector<int>> grid);

int main() {
	
	std::vector<std::vector<int>> grid = { {1} };

	std::string ans;
	while (true) {
		std::cout << "PRESS ENTER TO CONTINUE";
		std::cin.ignore();
		grid.insert(grid.begin(), std::vector<int>(grid.size() + 2, 0));
		grid.push_back(std::vector<int>(grid.size() + 1, 0));

		for (int i = 1; i < grid.size() - 1; i++) {
			grid[i].insert(grid[i].begin(), 0);
			grid[i].push_back(0);
		}


		fillSide(grid, grid.size() - 1, grid.size() - 2, 0, -1, 1);
		fillSide(grid, grid.size() - 1, 0, -1, 0, 0);
		fillSide(grid, 0, 0, 0, 1, 0);
		fillSide(grid, 0, grid.size() - 1, 1, 0, 0);

		std::cout << to_string(grid) << "\n";

		
	}
	
}


bool isPrime(int n) {
	if (n % 2 == 0) {
		return false;
	}
	if (n % 5 == 0) {
		return false;
	}
	for (int i = 3; i < sqrt(n); i += 2) {
		if (n % i == 0) {
			return false;
		}
	}
	return true;
}



void fillSide(std::vector<std::vector<int>>& grid, int x, int y, int xStep, int yStep, int c) {
	
	int prev;

	if (y == grid.size() - 1) { // Bottom
		prev = grid[y - 1][x];
	}
	else if (x == 0) { // Left
		prev = grid[y][x + 1];
	}
	else if (y == 0) { // Top
		prev = grid[y + 1][x];
	}
	else { // Right
		prev = grid[y][x - 1];
	}
	for (int i = 0; i < grid.size() - c; i++) {
		grid[y][x] = prev + 1;
		prev = grid[y][x];
		x += xStep;
		y += yStep;
	}
}


std::string to_string(std::vector<std::vector<int>> grid) {
	std::string str = "";
	int nLength = std::to_string(grid[grid.size() - 1][grid.size() - 1]).length();

	for (int i = 0; i < grid.size(); i++) {
		for (int ii = 0; ii < grid[i].size(); ii++) {
			std::string temp = std::to_string(grid[i][ii]);
			while (temp.length() < nLength) {
				temp = " " + temp;
			}
			str += temp + " ";
		}
		str += "\n";
	}
	return str;
}
