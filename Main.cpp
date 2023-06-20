// Defining modules
#include "Sudoku.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

// Creating main function
int main() {

	// input and output file
	ifstream fin("puzzle.txt");
	ofstream fout("solutions.txt");

	// Checking whether the file is opening or not
	if (!fin) {
		cout << "Sorry ! Cannot open the input file" << endl;
		system("pause");
		return -1;
	}

	// Default Board size
	int GRID_SIZE = 16;

	// Creating sudoku board
	vector<vector<char>> board(GRID_SIZE, vector<char>(GRID_SIZE));

	// Creating a vector for storing all the empty cells
	vector<elements> Empty;

	// Defining variable
	string line;

	// Using for loop to load all the data in board and empty vectors
	for (int row = 0; row < 16; row++) {

		getline(fin, line);

		for (int col = 0; col < 16; col++) {

			char val = line[col];

			// Appending all the empty value to the vector
			if (val == '.') {
				Empty.push_back({ row,col,val });
			}

			// Appending all the existing values to sudoku board
			else {
				board[row][col] = val;
			}
		}
	}

	// Creating class object puzzle
	Sudoku puzzle;

	// Using solve function to complete the game
	puzzle.solve(board,Empty,0,fout);

	// Closing all the files
	fin.close();
	fout.close();
;
	system("pause");
	return 0;

}