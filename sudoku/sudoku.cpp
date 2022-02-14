/*
	Programmer    : Mark Leard 
	Last modified : 26 Jan 22
	
	sudokustart.cpp
	
	Demonstrates file processing.
	Enters a Sudoku puzzle into a two-dimensional array.

	GRADING: 15/50

	Algorithm 0/10
	None found.
	Please correct this for the redo.

	Module Interface Table 0/10
	None found.
	Please correct this for the redo.

	Program 15/25
	Program compiles and runs with normal exit.
	The original Sudoku was not entered.
	I changed your input text file with the correct input data.
	Output table is incorrect.

	make sure correct testing data

	Additional comments
	No loadTable( table ) method found.
	Table should NOT be a global variable. Pass it as a parameter.
	Preconditions and Postconditions are statements that are true or false.
	Correct and redo.

	create a loadTable method

	Test Plan 0/5
	None found.
	Please correct this for the redo.

	make sure to turn in everything

	Issues:
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const string INFILENAME = "sudokutest.txt";

void findAndReplace(char target, int changeNumber);


int main()
{
	char[]  table[9][9];            // sudoku table
	int[]   finalTable[9][9];


	// constants and variables
	ifstream inFile;                 // input file variable
	string   buf;                    // input buffer

	char     value;                  // value read from file

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

	findAndReplace('7', 8, table, finalTable);
	findAndReplace('8', 9, table, finalTable);
	findAndReplace('9', 7, table, finalTable);
	cout << endl << endl << endl;

	for (int i = 0; i < 9; i++) {
		cout << endl;
		for (int a = 0; a < 9; a++)
			cout << finalTable[i][a] << " ";
	}
	return( 0 );
}

// include table as param and target
void findAndReplace(char target, int changeNumber, char[] table, int[] finalTable)
/*
* Pre :  a 9x9 grid of char 1-9
* Post: The completed board
*/
{
	for (int i = 0; i < 9; i++)
	{
		for (int a = 0; a < 9; a++)
		{
			if (table[i][a] == target)
			{
			 	finalTable[i][a] = (char)changeNumber;
			}
			else
			{
				finalTable[i][a] = ((int)table[i][a]);
			}
			
			cout << finalTable[i][a];
		}
	}
}


