// Defining modules
#include "Sudoku.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;
using std::exception;
using std::getline;
using std::string;
using std::ostream;
using std::endl;


// An const integer to represent the size of the board
const int Sudoku::SIZE = 16;

// A Character to represent the empty cell
const char Sudoku::BLANK = '.';

// Strings for trying all the possible values
const string Sudoku::VALUES = "0123456789abcdef";

// Integer for counting all the solutions
int Sudoku::solutionsCount = 0;



/*  Tests whether a digit already appears in a row , columns and grid.
    @param board: 16 by 16 hexadecimal sudoku board 
	@param row: index of the row to search
	@param col: index of the column to search
	@param value: value to test
	@return: {true} if the value is found in the row, column and grid; {false} otherwise
*/

bool Sudoku::Check_Col_Row_Grid(vector<vector<char>>& board, int row, int col, char value) {

	// checking all the rows whether value is already there
	for (int col = 0; col < SIZE; col++) {
		if (board[row][col] == value) {
			return false;
		}
	}
	 
	// checking all the cols whether value is already there
	for (int row = 0; row < SIZE; row++) {
		if (board[row][col] == value) {
			return false;
		}
	}

	// checking all the grids whether value is already there
	int gridStartRow = (row / 4) * 4;
	int gridStartCol = (col / 4) * 4;

	// Using loop to iterate through all the value in the grids.
	for (int i = gridStartRow; i < gridStartRow + 4; i++) {
		for (int j = gridStartCol; j < gridStartCol + 4; j++) {
			if (board[i][j] == value) {
				return false;
			}
		}
	}

	// the digit is valid if it passes all the checks
	return true;

}


/*  Solves the puzzle beginning with some cell.
    @param board: 16 by 16 hexadecimal sudoku board
	@param Empty: An Empty vector with all the empty cells
	@param fout: output stream to print all the solution
*/

void Sudoku::solve(vector<vector<char>>& board, vector<elements>& Empty, int index, ostream& fout) {

	// Base case; If puzzle is already solved
	if (index == Empty.size()) {

		// Adding number of solutions
		solutionsCount++;
		fout << "Solution " << solutionsCount << endl;
		fout << " " << endl;
		printSolution(board, fout);
		return;
	}

	// Creating struct variable to store row , col and val of the empty cell
	elements cell = Empty[index];

	// Iterating 16 times
	for (int i = 0; i < SIZE; i++) {

		// storing all the valid elements
		char val_1 = VALUES[i];

		// Checking whether value already present in sudoku board
		if (Check_Col_Row_Grid(board, cell.row, cell.col, val_1)) {

			// replace all the empty cells with valid elements
			board[cell.row][cell.col] = val_1;

			// moving to next empty cell
			solve(board, Empty, index + 1, fout);

			board[cell.row][cell.col] = BLANK;    // Back tracking
		}
	}
}


/*  Writes the solution to an output stream.
    @param board: 16 by 16 hexadecimal sudoku board
	@param fout: an output stream to write the solution
*/

void Sudoku::printSolution(vector<vector<char>>& board, ostream& fout) const {

	for (int row = 0; row < SIZE; row++) {
		for (int col = 0; col < SIZE; col++) {

			fout << board[row][col];
		}
		fout << endl;
	}
	fout << endl;
}