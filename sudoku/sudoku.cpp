/*
	Programmer    : Bob Harder
	Last modified : 26 Jan 22

	sudokustart.cpp

	Demonstrates file processing
	Enters a Sudoku puzzle into a two-dimensional array.
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const string INFILENAME = "sudokutest.txt";

int main()

{
	// constants and variables
	ifstream inFile;                 // input file variable
	string   buf;                    // input buffer

	char     value;                  // value read from file
	char     table[9][9];            // sudoku table

	int      linecount = 0;

	// open files
	// associate a file name with a file variable
	inFile.open(INFILENAME);
	if (!inFile)
	{
		cout << "Can't open input file " << INFILENAME << endl;
		return(1);
	}

	// process the file
// 	while (!inFile.eof())
	for (int row = 0; row < 9; row++)            // rows
	{
		for (int col = 0; col < 9; col++)        // columns
		{
			// read a new line of text
			getline(inFile, buf);

			// if the length of the line is not 0
			if (buf.length() != 0)
			{
				// get the first (and only) character in buf
				value = buf.at(0);

				// print value on the screen
				cout << value;

				// write value to the table
				table[row][col] = value;

				// increment linecount
				linecount++;
			}
		}
	}
	cout << endl;

	// close files
	inFile.close();

	// output results
	cout << "Line count : " << linecount << endl << endl;

	// display table
	for (int row = 0; row < 9; row++)            // rows
	{
		for (int col = 0; col < 9; col++)        // columns
		{
			cout << table[row][col] << " ";
		}
		cout << endl;
	}


	cout << endl;
	// food for thought
	// make pointer p point to the same address space as table
	char* p = *table;

	for (int i = 0; i < 81; i++)
		cout << p[i];
	cout << endl;


	return(0);
}
