/***********************************************************************
* COSC1076 - Advanced Programming Techniques
* Semester 2 2015 Assignment #1
* Full Name        : KIROLOS KALDAS
* Student Number   : s3545643
* Course Code      : COSC1076
* Program Code     : BP096
* Start up code provided by Paul Miller
***********************************************************************/
#include "game.h"


/* Checks for a row winner */
int checkRowWinner(struct player * current, enum cell_contents board[][BOARDWIDTH])
{
	BOOLEAN test;
	int i, j, true, false;
	true = false = 0;
	for (i = 0; i < BOARDHEIGHT; i++)
	{
		for (j = 0; j < BOARDWIDTH; j++)
		{
			if (board[i][j] == current->thiscolor)
			{
				/* checks for out of bounds to prevent seg faults */
				if (j + 3 < BOARDWIDTH)
				{
					if (board[i][j + 1] == current->thiscolor)
					{
						if (board[i][j + 2] == current->thiscolor)
						{
							if (board[i][j + 3] == current->thiscolor)
							{
								true++;
							}
						}
					}
				}
			}
			else
			{
				false++;
			}
		}
	}
	if (true > 0)
	{
		printf("\n%s is the Winner!\n", current->name);
		return test = TRUE;
	}
	else
	{
		return test = FALSE;
	}
}

/* Checks for a column winner */
int checkColumnWinner(struct player * current, enum cell_contents board[][BOARDWIDTH])
{
	BOOLEAN test;
	int i, j, true, false;
	true = false = 0;
	for (i = 0; i < BOARDHEIGHT; i++)
	{
		for (j = 0; j < BOARDWIDTH; j++)
		{
			if (board[i][j] == current->thiscolor)
			{
				/* checks for out of bounds to prevent seg faults */
				if (i + 3 < BOARDHEIGHT)
				{
					if (board[i + 1][j] == current->thiscolor)
					{
						if (board[i + 2][j] == current->thiscolor)
						{
							if (board[i + 3][j] == current->thiscolor)
							{
								true++;
							}
						}
					}
				}
			}
			else
			{
				false++;
			}
		}
	}
	if (true > 0)
	{
		printf("\n%s is the Winner!\n", current->name);
		return test = TRUE;
	}
	else
	{
		return test = FALSE;
	}
}

/* Checks for a diagonal winner */
int checkDiagonalTopRight(struct player * current, enum cell_contents board[][BOARDWIDTH])
{
	BOOLEAN test;
	int i, j, true, false;
	true = false = 0;
	for (i = 0; i < BOARDHEIGHT; i++)
	{
		for (j = 0; j < BOARDWIDTH; j++)
		{
			if (board[i][j] == current->thiscolor)
			{
				/* checks for out of bounds to prevent seg faults */
				if (i + 3 < BOARDHEIGHT && j + 3 < BOARDWIDTH)
				{
					if (board[i + 1][j + 1] == current->thiscolor)
					{
						if (board[i + 2][j + 2] == current->thiscolor)
						{
							if (board[i + 3][j + 3] == current->thiscolor)
							{
								true++;
							}
						}
					}
				}
			}
			else
			{
				false++;
			}
		}
	}
	if (true > 0)
	{
		printf("\n%s is the Winner!\n", current->name);
		return test = TRUE;
	}
	else
	{
		return test = FALSE;
	}
}

/* Checks for a diagonal winner */
int checkDiagonalTopLeft(struct player * current, enum cell_contents board[][BOARDWIDTH])
{
	BOOLEAN test;
	int i, j, true, false;
	true = false = 0;
	for (i = 0; i < BOARDHEIGHT; i++)
	{
		for (j = 0; j < BOARDWIDTH; j++)
		{
			if (board[i][j] == current->thiscolor)
			{
				/* checks for out of bounds to prevent seg faults */
				if (i - 3 > -1 && j - 3 > -1)
				{
					if (board[i - 1][j - 1] == current->thiscolor)
					{
						if (board[i - 2][j - 2] == current->thiscolor)
						{
							if (board[i - 3][j - 3] == current->thiscolor)
							{
								true++;
							}
						}
					}
				}
			}
			else
			{
				false++;
			}
		}
	}
	if (true > 0)
	{
		printf("\n%s is the Winner!\n", current->name);
		return test = TRUE;
	}
	else
	{
		return test = FALSE;
	}
}

/* Checks for a diagonal winner */
int checkDiagonalBottomRight(struct player * current, enum cell_contents board[][BOARDWIDTH])
{
	BOOLEAN test;
	int i, j, true, false;
	true = false = 0;
	for (i = 0; i < BOARDHEIGHT; i++)
	{
		for (j = 0; j < BOARDWIDTH; j++)
		{
			if (board[i][j] == current->thiscolor)
			{
				/* checks for out of bounds to prevent seg faults */
				if (i - 3 > -1 && j + 3 < BOARDWIDTH)
				{
					if (board[i - 1][j + 1] == current->thiscolor)
					{
						if (board[i - 2][j + 2] == current->thiscolor)
						{
							if (board[i - 3][j + 3] == current->thiscolor)
							{
								true++;
							}
						}
					}
				}
			}
			else
			{
				false++;
			}
		}
	}
	if (true > 0)
	{
		printf("\n%s is the Winner!\n", current->name);
		return test = TRUE;
	}
	else
	{
		return test = FALSE;
	}
}

/* Checks for a diagonal winner */
int checkDiagonalBottomLeft(struct player * current, enum cell_contents board[][BOARDWIDTH])
{
	BOOLEAN test;
	int i, j, true, false;
	true = false = 0;
	for (i = 0; i < BOARDHEIGHT; i++)
	{
		for (j = 0; j < BOARDWIDTH; j++)
		{
			if (board[i][j] == current->thiscolor)
			{
				/* checks for out of bounds to prevent seg faults */
				if (i + 3 < BOARDHEIGHT && j - 3 > -1)
				{
					if (board[i + 1][j - 1] == current->thiscolor)
					{
						if (board[i + 2][j - 2] == current->thiscolor)
						{
							if (board[i + 3][j - 3] == current->thiscolor)
							{
								true++;
							}
						}
					}
				}
			}
			else
			{
				false++;
			}
		}
	}
	if (true > 0)
	{
		printf("\n%s is the Winner!\n", current->name);
		return test = TRUE;
	}
	else
	{
		return test = FALSE;
	}
}

/* Checks if the board is empty which would mean that its the first turn */
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

/* Checks if the board is full */
int fullBoard(enum cell_contents board[][BOARDWIDTH])
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
	if (true == 0)
	{
		return test = FALSE;
	}
	else
	{
		return test = TRUE;
	}
}

/* This function swaps the players for every round */
static void swap_players(struct player ** current, struct player ** other)
{
	struct player * temp;
	temp = NULL;
	temp = *current;
	*current = *other;
	*other = temp;
}

/**
* This is the heart of the game.
*
* Firstly, you need to initialise the game by calling functions written
* for requirement 3. The rest of this function is then managing the game
* loop.
*
* Each player takes a turn to drop a token into a column on the game
* board. The task that needs to be performed will be different depending
* on whether this is a human or a computer player.
*
* Regardless of the player type, you will need to display the board as it
* was before the player makes their move. If the current player is a
* computer player, we just need to select a column at random and drop a
* token into that column. If there is no room, try another column.
*
* If the current player is a human player, your program will need to ask
* the user what column they wish to drop a token in. This input should be
* validated to check that it is numeric and within the range of allowed
* columns.
*
* Once a valid move has been entered, your program should update the
* gameboard. It should then check if the game has been won lost or drawn
* by calling and the change the current player.
*
* This function also checks if the game has been won, lost or drawn by
* calling \ref test_for_winner(), and if the game is over, returns the
* winner to main or NULL if the game was a draw.

* @param human a pointer to details about the human player
* @param computer a pointer to details about the computer player
**/
struct player * play_game(struct player * human,
struct player * computer)
{
	/* declaration that allocates the board for the game */
	enum cell_contents board[BOARDHEIGHT][BOARDWIDTH];
	struct player *current, *other;
	enum game_state winner;

	initialise_board(board);

	if (get_human_player(human) == RTM)
	{
		return NULL;
	}

	get_computer_player(computer);

	/* This statement declares the currnt and other */
	if (human->thiscolor == C_WHITE)
	{
		current = human;
		other = computer;
	}
	else
	{
		current = computer;
		other = human;
	}

	do
	{
		/* If the baord is empty, print the board an extra time */
		if (emptyBoard(board) == TRUE)
		{
			display_board(board);
		}
		
		/* The current player gets a turn */
		if (take_turn(current, board) == RTM)
		{
			return NULL;
		}
		
		display_board(board);
		
		/* Check for winner */
		winner = test_for_winner(current, board);
		
		/* Swapping the current player to the other player */
		swap_players(&current, &other);
	} while (winner == G_NO_WINNER);
	
	if (winner == G_RED)
	{
		if (human->thiscolor == C_RED)
		{
			return human;
		}
		else
		{
			return computer;
		}
	}
	else if (winner == G_WHITE)
	{
		if (human->thiscolor == C_WHITE)
		{
			return human;
		}
		else
		{
			return computer;
		}
	}
	else 
	{
		/* Should be a draw... */
		return NULL;
	}
}

/* This function test for the winner */
enum game_state test_for_winner(struct player * current, 
enum cell_contents board[][BOARDWIDTH])
{
	enum game_state test = G_NO_WINNER;

	/* Checks for each type of winner */
	if (checkColumnWinner(current, board) == TRUE || checkRowWinner(current, board) == TRUE
		|| checkDiagonalTopLeft(current, board) == TRUE || checkDiagonalTopRight(current, board) == TRUE
		|| checkDiagonalBottomRight(current, board) == TRUE || checkDiagonalBottomLeft(current, board) == TRUE)
	{
		if (current->thiscolor == C_RED)
		{
			test = G_RED;
		}
		else if (current->thiscolor == C_WHITE)
		{
			test = G_WHITE;
		}
	}
	/* If the board is full and no winners, means the game ended in a draw */
	else if (fullBoard(board) == FALSE)
	{
		printf("\nGame has ended. Its a draw.\n");
		test = G_DRAW;
	}
	else
	{
		test = G_NO_WINNER;
	}
	
	return test;
}

