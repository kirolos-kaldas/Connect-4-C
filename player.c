/***********************************************************************
* COSC1076 - Advanced Programming Techniques
* Semester 2 2015 Assignment #1
* Full Name        : EDIT HERE
* Student Number   : EDIT HERE
* Course Code      : EDIT HERE
* Program Code     : EDIT HERE
* Start up code provided by Paul Miller
***********************************************************************/
#include "player.h"
color playersColor;

int emptyBoard(enum cell_contents board[][BOARDWIDTH])
{
	BOOLEAN test;
	int i, j, true, false;
	true = false = 0;;
	for (i = 0; i < BOARDHEIGHT; i++)
	{
		for (j = 0; j < BOARDWIDTH; j++)
		{
			if (board[i][j] == C_EMPTY)
			{
				true++;
			}
			else
			{
				false++;
			}
		}
	}
	if (false == 0)
	{
		return test = TRUE;
	}
	else
	{
		return test = FALSE;
	}
}

int firstTurn(enum cell_contents board[][BOARDWIDTH])
{
	BOOLEAN test;
	int i, j, true, false;
	true = false = 0;
	for (i = 0; i < BOARDHEIGHT; i++)
	{
		for (j = 0; j < BOARDWIDTH; j++)
		{
			if (board[i][j] == C_EMPTY)
			{
				true++;
			}
			else
			{
				false++;
			}
		}
	}

	if (false < 2)
	{
		test = TRUE;
	}
	else
	{
		test = FALSE;
	}
	return test;
}

int compColumnChoice(struct player * current, int * numColumn)
{
	*numColumn = 0;

	*numColumn = rand() % BOARDWIDTH;
	if (*numColumn == 0)
	{
		*numColumn = 1;
	}
	current->counters++;

	return *numColumn;
}

int humanColumnChoice(struct player * current, int * numColumn)
{
	BOOLEAN test;
	char column[INPUT_SIZE + 2];
	char *pointer;
	*numColumn = 0;

	do
	{
		fgets(column, INPUT_SIZE + 2, stdin);

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
	} while (test != TRUE);
	
	return *numColumn;
}

/**
* @param human the human player to initialise
**/
enum input_result get_human_player(struct player* human)
{
	char name[NAMELEN + 1];
	BOOLEAN test;

	printf("\nWhat is your name?\n");
	do
	{
		fgets(name, NAMELEN + 1, stdin);

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
	} while (test != TRUE);

	/* This statement is used to copy strings. strycpy_s is used only on visual so if
	the code is run on server need to comment out strcpy_s and uncomment strcpy.*/
	/*strcpy_s(&human->name, NAMELEN + 1, name);*/
	strcpy(&human->name, name);

	playersColor = rand() % 2;

	if (playersColor == 0)
	{
		playersColor = C_RED;
	}

	if (playersColor == C_RED)
	{
		human->thiscolor = C_RED;
	}
	else if (playersColor == C_WHITE)
	{
		human->thiscolor = C_WHITE;
	}

	human->counters = 0;

	human->type = HUMAN;
	/* placeholder return value. You should prompt the user
	* for their name and then initialise all other values in the
	* player struct to sensible values.
	*/
	return SUCCESS;
}

/**
* @param computer the computer player to initialise
**/
enum input_result get_computer_player(struct player * computer)
{
	char name[9] = "Computer";
	/*strcpy_s(&computer->name, NAMELEN + 1, name);*/
	strcpy(&computer->name, name);

	if (playersColor == C_RED)
	{
		computer->thiscolor = C_WHITE;
	}
	else
	{
		computer->thiscolor = C_RED;
	}

	computer->counters = 0;

	computer->type = COMPUTER;
	/* initialise all variables that are part of the struct to sensible
	* values */

	return FAILURE;
}

/**
* In this requirement, you need to handle the taking of a turn - either
* of a human or a computer player.
*
* For the human player, you will need to allow the user to enter the
* column they wish to place a token in. You will need to validate what
* the user enters, then place a token correctly in that column so that
* it occupies the cell closest to the bottom of the board array for that
* column.
*
* For the computer player, you will need to randomly generate a column
* number to place a token in and if that column is full, generate a
* different column number until a column number with some free space has
* been found.
*
* @param current the current player
* @param board the game board that we will attempt to insert a token into
* @return enum @ref input_result indicating the state of user input (in
* case this run involved user input
**/
enum input_result take_turn(struct player * current, struct player * human,
struct player* computer, enum cell_contents board[][BOARDWIDTH])
{
	char column[INPUT_SIZE + 2];
	char *pointer;
	int numColumn;
	int bottomColumn;
	int i, j;
	BOOLEAN test = FALSE;

	/*current->type = rand() % 2;
	if (current->type == 0)
	{
	current->type = 1;
	}*/

	if (emptyBoard(board) == TRUE)
	{
		current->thiscolor = C_WHITE;
		if (current->thiscolor == human->thiscolor)
		{
			/*strcpy_s(current->name, NAMELEN + 1, human->name);*/
			strcpy(current->name, human->name);
			current->thiscolor = human->thiscolor;
			current->counters = human->counters;
			current->type = human->type;
			humanColumnChoice(&current, &numColumn);

			/*fgets(column, INPUT_SIZE + 2, stdin);

			//refrence
			if (column[strlen(column) - 1] != '\n')
			{
				read_rest_of_line();
				numColumn = (int)strtol(column, &pointer, 10);
			}
			else
			{
				column[strlen(column) - 1] = '\0';
				numColumn = strtol(column, &pointer, 10);
			}*/
		}
		else if (current->thiscolor == computer->thiscolor)
		{
			/*strcpy_s(current->name, NAMELEN + 1, computer->name);*/
			strcpy(current->name, computer->name);
			current->thiscolor = computer->thiscolor;
			current->counters = computer->counters;
			current->type = computer->type;
			compColumnChoice(&current, &numColumn);

			/*numColumn = rand() % BOARDWIDTH;
			if (numColumn == 0)
			{
				numColumn = 1;
			}*/
		}
	}

	/*if (current->thiscolor == C_WHITE && emptyBoard(board) == TRUE)
	{
	columnChoice(&current, &numColumn);
	}*/

	if (emptyBoard(board) == FALSE)
	{
		if (firstTurn(board) == TRUE)
		{
			if (current->type == HUMAN)
			{
				/*strcpy_s(current->name, NAMELEN + 1, computer->name);*/
				strcpy(current->name, computer->name);
				current->thiscolor = computer->thiscolor;
				current->counters = computer->counters;
				current->type = computer->type;
				compColumnChoice(&current, &numColumn);
			}
			else if (current->type == COMPUTER)
			{
				/*strcpy_s(current->name, NAMELEN + 1, human->name);*/
				strcpy(current->name, human->name);
				current->thiscolor = human->thiscolor;
				current->counters = human->counters;
				current->type = human->type;
				humanColumnChoice(&current, &numColumn);
			}
		}
		else
		{
			if (current->type == COMPUTER)
			{
				humanColumnChoice(&current, &numColumn);
				current->type = human->type;
			}
			else if (current->type == HUMAN)
			{
				compColumnChoice(&current, &numColumn);
				current->type = computer->type;
			}
		}
		/*if (current->type == HUMAN)
		{
			humanColumnChoice(&current, &numColumn);
		}
		else if (current->type == COMPUTER)
		{
			compColumnChoice(&current, &numColumn);
		}*/
	}

	current->counters++;

	bottomColumn = 5;

	for (i = 0; i < BOARDHEIGHT; i++)
	{
		for (j = 0; j < BOARDWIDTH; j++)
		{
			if (numColumn == j + 1)
			{
				do
				{
					if (board[i + bottomColumn][j] == C_EMPTY)
					{
						board[i + bottomColumn][j] = current->thiscolor;
						test = TRUE;
					}
					else
					{
						bottomColumn--;
					}
				} while (test == FALSE);
			} 
		}
	}

	/*
	* Default return value - delete this comment and the return
	* value and replace it with appropriate logic to handle either
	* a human or computer turn including handling any input errors.
	*/
	return FAILURE;
}
