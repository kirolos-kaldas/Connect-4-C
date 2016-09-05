/***********************************************************************
* COSC1076 - Advanced Programming Techniques
* Semester 2 2015 Assignment #1 
* Full Name        : KIROLOS KALDAS
* Student Number   : s3545643
* Course Code      : COSC1076
* Program Code     : BP096
* Start up code provided by Paul Miller
***********************************************************************/
#include "player.h"
color colorPlayer;

/* Randomly generates a column number */
int compColumnChoice(struct player * current, int * numColumn)
{
	*numColumn = 0;

	*numColumn = rand() % BOARDWIDTH;
	if (*numColumn == 0)
	{
		*numColumn = 1;
	}

	return *numColumn;
}

/* This functions makes the user input the desired column number */
int humanColumnChoice(struct player * current, int * numColumn)
{
	BOOLEAN test;
	char column[INPUT_SIZE + 2];
	char *pointer;
	*numColumn = 0;

	do
	{
		/* If the user inputs control-d, it will return him to the menu */
		if (fgets(column, INPUT_SIZE + 2, stdin) == NULL)
		{
			printf("\n%s has quit the game!\n", current->name);
			return RTM;
		}
		/* If the user inputs '\n', it will return him to the menu */
		else if (strcmp(column, "\n") == 0)
		{
			printf("\n%s has quit the game!\n", current->name);
			return RTM;
		}
		else
		{
			/****************************************************************************
			* Refrence to the use of fgets function
			* Steven Burrows
			* sdb@cs.rmit.edu.au
			* Created July 2004.
			****************************************************************************/
			if (column[strlen(column) - 1] != '\n')
			{
				printf("The column number entered doesn't exist. Re-Enter Column Number: ");
				read_rest_of_line();
				test = FALSE;
			}
			else
			{
				column[strlen(column) - 1] = '\0';
				*numColumn = (int)strtol(column, &pointer, 10);
				test = TRUE;
				
				if (*numColumn > 0 && *numColumn < 8)
				{
					test = TRUE;
				}
				else
				{
					printf("The column number entered doesn't exist. Re-Enter Column Number: ");
					test = FALSE;
				}
			}
		}
	} while (test != TRUE);
	
	return *numColumn;
}

/**
*  Initialises the human player
**/
enum input_result get_human_player(struct player* human)
{
	char name[NAMELEN + 1];
	BOOLEAN test;

	printf("\nWhat is your name?\n");
	do
	{
		/* If the user inputs control-d, it will return him to the menu */
		if (fgets(name, NAMELEN + 1, stdin) == NULL)
		{
			printf("The player has quit before they got started!\n");
			return RTM;
		}
		/* If the user inputs '\n', it will return him to the menu */
		else if (strcmp(name, "\n") == 0)
		{
			printf("The player has quit before they got started!\n");
			return RTM;
		}
		else
		{
			/****************************************************************************
			* Refrence to the use of fgets function
			* Steven Burrows
			* sdb@cs.rmit.edu.au
			* Created July 2004.
			****************************************************************************/
			if (name[strlen(name) - 1] != '\n')
			{
				/* String was too long. Reject string and flush input buffer. */
				printf("The name entered is too long. Re-Enter Name:\n");
				read_rest_of_line();
				test = FALSE;
			}
			else
			{
				/* String length was ok. Remove the '\n' character. */
				name[strlen(name) - 1] = '\0';
				test = TRUE;
			}
		}
	} while (test != TRUE);

	/* Copy the inputed name to the human name */
	strcpy(human->name, name);

	/* To generate a random number */
	srand(time(NULL));

	/* Generate a random color */
	colorPlayer = rand() % 2;

	if (colorPlayer == 0)
	{
		colorPlayer = C_WHITE;
	}

	human->thiscolor = colorPlayer;

	human->counters = 0;

	human->type = HUMAN;
	
	return SUCCESS;
}

/**
*  Initialise computer player
**/
enum input_result get_computer_player(struct player * computer)
{
	char name[NAMELEN + 1] = "Computer";
	strcpy(computer->name, name);

	if (colorPlayer == C_RED)
	{
		computer->thiscolor = C_WHITE;
	}
	else
	{
		computer->thiscolor = C_RED;
	}

	computer->counters = 0;

	computer->type = COMPUTER;
	
	return SUCCESS;
}

/**
  This function allows each player to have a turn and adds the token entered by the player 
  to the game board
**/
enum input_result take_turn(struct player * current, enum cell_contents board[][BOARDWIDTH])
{
	int numColumn = 0;
	int bottomColumn;
	int i, j;
	BOOLEAN test = FALSE;

	if (current->type == HUMAN)
	{
		if (humanColumnChoice(current, &numColumn) == RTM)
		{
			return RTM;
		}
	}
	else if (current->type == COMPUTER)
	{
		compColumnChoice(current, &numColumn);
	}

	current->counters++;

	/* This variable is used to get the board to start adding to the board 
	from the bottom of it */
	bottomColumn = 5;
	
	for (i = 0; i < BOARDHEIGHT; i++)
	{
		for (j = 0; j < BOARDWIDTH; j++)
		{
			/* Checks if the column number inputed exists */
			if (numColumn == j + MINCOLUMN)
			{
				do
				{
					/* checks for out of bounds to prevent seg faults */
					if (i + bottomColumn < BOARDHEIGHT && numColumn - MINCOLUMN < BOARDWIDTH)
					{
						/* Checks if the block cell is empty to add a token */
						if (board[i + bottomColumn][numColumn - MINCOLUMN] == C_EMPTY)
						{
							board[i + bottomColumn][numColumn - MINCOLUMN] = current->thiscolor;
							test = TRUE;
						}
						/* Checks if the column chosen is full and if it is, it asks for a 
						new column of the current player */
						else if (i + bottomColumn < 0)
						{
							bottomColumn = 5;
							if (current->type == HUMAN)
							{
								printf("The column chosen is full. Re-Enter Column Number: ");
								if (humanColumnChoice(current, &numColumn) == RTM)
								{
									return RTM;
								}
							}
							else if (current->type == COMPUTER)
							{
								compColumnChoice(current, &numColumn);
							}
						}
						else
						{
							/* Decreases the depth of the column to add a token */
							bottomColumn--;
						}
					}
				} while (test == FALSE);
			}
		}
	}

	return SUCCESS;
}
