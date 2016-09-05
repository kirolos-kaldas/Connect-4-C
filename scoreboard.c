/***********************************************************************
* COSC1076 - Advanced Programming Techniques
* Semester 2 2015 Assignment #1 
* Full Name        : KIROLOS KALDAS
* Student Number   : s3545643
* Course Code      : COSC1076
* Program Code     : BP096
* Start up code provided by Paul Miller
***********************************************************************/
#include "scoreboard.h"

/* Checks if the scoreboard is full or not */
int fullScoreboard(scoreboard board)
{
	BOOLEAN test;
	int i, true, false;
	true = false = 0;;
	for (i = 0; i < SCOREBOARDSIZE; i++)
	{
		if (board[i].counters == 0)
		{
			true++;
		}
		else
		{
			false++;
		}
	}
	if (true == 0)
	{
		return test = TRUE;
	}
	else
	{
		return test = FALSE;
	}
}

/**
* This function initializes the scoreboard
**/
void init_scoreboard(scoreboard board)
{
	int i;
	/* Loops in the scoreboard array to give a null value to the
	variables needed for the scoreboard in the player struct */
	for (i = 0; i < SCOREBOARDSIZE; i++)
	{
		/* Initializes every player's name to null */
		strcpy(board[i].name, "\0");

		/* Initializes every player's counters to zero */
		board[i].counters = 0;
	}
}

/**
 * This function displays the scoreboard
 **/
void display_scores(const scoreboard board)
{
	int i;
	printf("Player\t\t|Score\t\t\n");
	printf("---------------------------------\n");

	for (i = 0; i < SCOREBOARDSIZE; i++)
	{
		/* Checks if the current score in the array is not 0 because if it is 
		0, there will be no need to print */
		if (board[i].counters != 0)
		{
			/* Checks if the name of the player is long to shorten the spaces when
			printing */
			if (strlen(board[i].name) > 7)
			{
				printf("%s\t|%d\t\t\n", board[i].name, board[i].counters);
			}
			else
			{
				printf("%s\t\t|%d\t\t\n", board[i].name, board[i].counters);
			}
		}
	}
}

/** 
 * This function adds the score and the name of the winner to the scoreboard
 * in the order from highest to lowest
 **/ 
 BOOLEAN add_to_scoreboard(scoreboard board, const score * sc) 
 {
	 BOOLEAN test = FALSE;
	 /* A holder of struct player */
	 struct player temp;
	 int i;
	 for (i = 0; i < SCOREBOARDSIZE; i++)
	 {
		 /* Checks if the scoreboard block is empty to make sure that it 
		 adds the values of thescoreboard in an block in the scoreboard line */
		 if (board[i].counters == 0)
		 {
			 /* This statement makes sure that the adding of the name and score is 
			 added only once */
			 if (test == FALSE)
			 {
				 /* Copy the name of the winner to the name to be placed on the board */
				 strcpy(board[i].name, sc->name);
				 
				 /* Adds the new score of the winner to board */
				 board[i].counters = sc->counters;
				 test = TRUE;
			 }
		 }
		 /* Checks if the board is in full and that the last score on the board is
		 less than or equal to the new winners score to delete the last winner on the board
		 and add the latest one */
		 else if (board[9].counters <= sc->counters && fullScoreboard(board) == TRUE)
		 {
			 strcpy(board[9].name, sc->name);
			 board[9].counters = sc->counters;
		 }
	 }

	 /* This loop checks the the order and re oreders the information on the scoreboard
	 if needed */
	 for (i = SCOREBOARDSIZE - 1; i > -1; i--)
	 {
		 /* checks for out of bounds to prevent seg faults */
		 if (i - 1 >= 0)
		 {
			 if (board[i].counters > board[i - 1].counters)
			 {
				 /* It swaps the players to reorder them */
				 temp = board[i];
				 board[i] = board[i - 1];
				 board[i - 1] = temp;
			 }
		 }
	 }
	 
    return TRUE; 
}
