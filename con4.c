/***********************************************************************
* COSC1076 - Advanced Programming Techniques
* Semester 2 2015 Assignment #1
* Full Name        : KIROLOS KALDAS
* Student Number   : s3545643
* Course Code      : COSC1076
* Program Code     : BP096
* Start up code provided by Paul Miller
***********************************************************************/
#include "con4.h"

/* This function prints the menu of options */
void displayMenu()
{
	printf("\nWelcome to Connect 4\n");
	printf("----------------------\n");
	printf("1. Play Game\n");
	printf("2. Display High Scores\n");
	printf("3. Quit\n\n");
	printf("Please Enter Your Choice: ");
}

int main(void)
{
	char choice[INPUT_SIZE + 2];
	char *pointer;
	int menuChoice = 0;

    /* the scoreboard for keeping track of winners */
    scoreboard scores;
    /* the two players and a pointer to who won the last game */
    struct player human_player, computer_player, *winner;

	srand(time(NULL));

    /* initialise the scoreboard */
	init_scoreboard(scores);

	do
	{
		/* display menu and get menu choice until the user chooses to quit */
		displayMenu();

		fgets(choice, INPUT_SIZE + 2, stdin);
		
		/****************************************************************************
		* Refrence to the use of fgets function
		* Steven Burrows
		* sdb@cs.rmit.edu.au
		* Created July 2004.
		****************************************************************************/
		if( choice[strlen(choice) - 1] != '\n' )
		{
			read_rest_of_line();
			menuChoice = (int) strtol(choice, &pointer, 10);
		}
		else
		{
			choice[strlen(choice) - 1] = '\0';
			menuChoice = strtol(choice, &pointer, 10);
		}


		switch(menuChoice)
		{
			/* play a game option */
			case 1:
				/* Get the returned value of the play game */
				winner = play_game(&human_player, &computer_player);
				
				/* if there was not a draw, add player to the scoreboard in
				order by number of tokens in play */
				if(winner != NULL)
				{
					add_to_scoreboard(scores, winner);	
				}
				break;

			/* display the scoreboard option */
			case 2:
				printf("Show High Score\n\n");
				display_scores(scores);
				break;

			/* quit the program option */
			case 3:
				printf("Quit Game\n\n");
				break;

			default:
				printf("Invalid Input.\n\n");
		}
	}
	while (menuChoice != 3);

	return EXIT_SUCCESS;
}
