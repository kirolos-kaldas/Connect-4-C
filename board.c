/***********************************************************************
* COSC1076 - Advanced Programming Techniques
* Semester 2 2015 Assignment #1
* Full Name        : EDIT HERE
* Student Number   : EDIT HERE
* Course Code      : EDIT HERE
* Program Code     : EDIT HERE
* Start up code provided by Paul Miller
***********************************************************************/
#include "board.h"
#include "player.h"

/**
* @file board.c contains implementations of functions related to the game
* board.
**/

/**
* @param board the board to reset the contents of
**/
void initialise_board(enum cell_contents board[][BOARDWIDTH])
{
	int i, j;
	for (i = 0; i < BOARDHEIGHT; i++)
	{
		for (j = 0; j < BOARDWIDTH; j++)
		{
			board[i][j] = C_EMPTY;
		}
	}
}

/**
* In this requirement you are required to display the game board.
* The game board should be displayed as shown on the first page of the
* assignment specification.
* @param board the board to display
**/
void display_board(enum cell_contents board[][BOARDWIDTH])
{
	printf("This is the current state of the board:\n\n");
	printf(" 1 | 2 | 3 | 4 | 5 | 6 | 7 |\n");
	printf("----------------------------\n");

	int i, j;
	for (i = 0; i < BOARDHEIGHT; i++)
	{
		for (j = 0; j < BOARDWIDTH; j++)
		{
			if (board[i][j] == C_WHITE)
			{
				printf(" %s |", WHITE_TOKEN);
			}
			else if (board[i][j] == C_RED)
			{
				printf(" %s |", RED_TOKEN);
			}
			else
			{
				printf("   |");
			}
			/*bottomColumn = 6;

			if( column == j )
			{
			if( board[i + bottomColumn][j] == C_EMPTY )
			{
			// if computer player, board[i + bottomColumn][j] = C_WHITE;
			// if human player, board[i + bottomColumn][j] = C_RED;
			bottomColumn--;
			}
			}*/
		}
		printf("\n----------------------------\n");
	}
	printf("Please enter a column in which to drop a token: ");

	/*printf("This is the current state of the board:\n\n");
	printf(" 1 | 2 | 3 | 4 | 5 | 6 | 7 |\n");
	printf("----------------------------\n"
	" %d | %d | %d | %d | %d | %d | %d |\n"
	"----------------------------\n"
	" %d | %d | %d | %d | %d | %d | %d |\n"
	"----------------------------\n"
	" %d | %d | %d | %d | %d | %d | %d |\n"
	"----------------------------\n"
	" %d | %d | %d | %d | %d | %d | %d |\n"
	"----------------------------\n"
	" %d | %d | %d | %d | %d | %d | %d |\n"
	"----------------------------\n"
	" %d | %d | %d | %d | %d | %d | %d |\n"
	"----------------------------\n", board);
	printf("Please enter a column in which to drop a token: ");*/
}


