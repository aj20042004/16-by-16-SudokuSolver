#ifndef Sudoku_H
#define Sudoku_H

// Defining modules
#include <iostream>
#include <vector>
#include <string>

using namespace std;
using std::istream;
using std::ostream;

// Creating Struct elements to access columns , row  and value of empty cell
struct elements {
	 int row;
	 int col;
	 char val;
};

// Creating class Sudoku
class Sudoku {

public:
	// Class-member function  
	void solve(vector<vector<char>>& , vector<elements>&, int, ostream& );     // Solves the 16 by 16 hexadecimal sudoku puzzle beginning with some cell.
	void printSolution(vector<vector<char>>& , ostream&) const;               // Write All the solution to output stream


private:
	// data fields 
	static int solutionsCount;   // Integer to count number of solutions
	static const int SIZE;       // default size of the array 
	static const char BLANK;     // character to represent blank cell 
	static const string VALUES;   // All the valid values 

	// checks if the alphabet or digit already exists in row 
	bool Check_Col_Row_Grid(vector<vector<char>>& , int, int, char) ;  
		    
};

#endif 


