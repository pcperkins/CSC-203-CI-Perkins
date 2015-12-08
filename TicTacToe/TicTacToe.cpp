// Peter Perkins
// Tic Tac Toe Game
// August 19, 2015

/*
The purpose of this program is to serve as an example of C++ programming.
Feel free to edit whatever you like to see if you can change it.
*/

// Libraries go here. A library has a bunch of functions contained in it
// so you don't have to reinvent the wheel whenever you program.
#include <iostream> // Used for input/output streams such as keyboard input and console (screen) output.
#include <string>	// Used for the string data type.
using namespace std;
// Here is where we declare other functions that the main function will use.
void SwapPlayers(char *player);
void DisplayBoard(char * board);
void ClearBoard(char * board);
bool Winner(char * board);

// This is our entry point, where we begin. "void" indicates that this function doesn't return
// a value.
void main()
{
	// Constant data types declared here. These cannot be modified by the program.
	const int numSquares = 9;

	// Declare the main data types here.
	char player = 'X';	// Char (short for character) is a data type
	char selection;		// that holds 8 bits which represent a bit of text or formatting data.
						// An ASCII table (available online) shows the conversion from a character
						// to a number.
	int numOfTurns; // Another common data type. Ints are usually 32 bits long, but only hold
	int boardSpace;		// integers. It can hold most positive or negative numbers, as long as there's
						// no decimal.
	char board[numSquares]; // The square brackets [] indicate that this is an array, or a
							// logical collection of the same data type. The number between
							// the brackets tells you how many elements there are in the array, in this case, 9.
							// In this case, writing board[0] returns the first element in the array.
							// Since we start counting at 0, the highest valid index for this array is 8;
	
	bool victory = false;	// The bool data type has only two options, true or false. 
	
	// Okay, now that we've set up all our storage, begin the program.

	// As long as the condition in the parentheses is true, the loop executes
	// everything in brackets. When it reaches the end of the instructions, it'll
	// re-evaluate the condition. Since "true" is always true, this will execute endlessly.
	while (true)
	{
		ClearBoard(board);
		numOfTurns = 0;
		while (victory == false && numOfTurns < numSquares)
		{
			DisplayBoard(board);	// Clears the screen and updates the board.
			cin.get(selection);		// Reads one key press from the user and stores it in "selection"
		
			boardSpace = static_cast<int>(selection);	// We got the user's input, so now we convert from text
			boardSpace = boardSpace - 48;				// to a usable number. Numbers 0-9 are ASCII codes 48-57,
														// so subtracting 48 produces the correct number.
			// This loop makes sure the user doesn't enter an invalid number.
			while (boardSpace > 9 || boardSpace < 1 || board[boardSpace - 1] != ' ')
			{
				cin.get(selection);
				boardSpace = static_cast<int>(selection) - 48; // combining steps here
			}
			
			board[boardSpace - 1] = player; // now we assign the player's letter to the space.

			// Check for a winner.
			if (Winner())
				;


			SwapPlayers(&player); // the ampersand (&) means we're passing in the address of the variable, so we can modify it directly.

			numOfTurns++; // the ++ means we're incrementing the variable, or adding 1 to its current value.
		

		}

		cin.get(selection);
		
	}
	



	

	return;
}

void DisplayBoard(char * board)
{

	for (int i = 0; i < 9; i++)
	{
		cout << " " << board[i];

		if ((i + 1) % 3 == 0 && i != 8)
		{
			cout << "\n";
			cout << "--------------------------";
		}
		else 
		{
			cout << " | ";
		}


	}

	return;
}

// Careful! This function uses a pointer, marked by the asterisk (*).
// Pointers hold addresses, usually the address of a variable.
// If you want to modify what the pointer represents, put a * before its name;
// otherwise, you're modifying the address it's pointing to.
void SwapPlayers(char * player)
{
	if (*player == 'X')
		*player = 'O';
	else 
		*player = 'X';
	return;
}

void ClearBoard(char * board)
{
	for (int i = 0; i < 8; i++)
	{
		board[i] = ' ';
	}
}