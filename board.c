/***********************************************************************
* COSC1076 - Advanced Programming Techniques
* Semester 2 2015 Assignment #1
* Full Name        : KIROLOS KALDAS
* Student Number   : s3545643
* Course Code      : COSC1076
* Program Code     : BP096
* Start up code provided by Paul Miller
***********************************************************************/
#include "board.h"
#include "player.h"

/**
*  Initialize the game board
**/
void initialise_board(enum cell_contents board[][BOARDWIDTH])
{
	int i, j;
	for (i = 0; i < BOARDHEIGHT; i++)
	{
		for (j = 0; j < BOARDWIDTH; j++)
		{
			/* makes all the board empty */
			board[i][j] = C_EMPTY;
		}
	}
}

/**
* This function displays the game board
**/
void display_board(enum cell_contents board[][BOARDWIDTH])
{
	int i, j;
	
	printf("\nThis is the current state of the board:\n\n");
	printf(" 1 | 2 | 3 | 4 | 5 | 6 | 7 |\n");
	printf("----------------------------\n");

	for (i = 0; i < BOARDHEIGHT; i++)
	{
		for (j = 0; j < BOARDWIDTH; j++)
		{
			/* if white print the white token, else print the red */
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
		}
		printf("\n----------------------------\n");
	}
	printf("Please enter a column in which to drop a token: ");
}


