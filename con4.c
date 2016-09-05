/***********************************************************************
* COSC1076 - Advanced Programming Techniques
* Semester 2 2015 Assignment #1 
* Full Name        : EDIT HERE
* Student Number   : EDIT HERE
* Course Code      : EDIT HERE
* Program Code     : EDIT HERE
* Start up code provided by Paul Miller
***********************************************************************/
#include "con4.h"

/**
 * @mainpage COSC1076 - Assignment 1 documentation.
 *
 * This is the main html documentation of assignment 1 for COSC1076 -
 * Advanced Programming Techniques for semester 2, 2015. You will find
 * here a description of the functions that you need to implement for
 * your assignment.
 *
 * Please note that this should not be your first stop when starting
 * your assignment. Please read the assignment 1 specifications that
 * are available on blackboard before reading this documentation. The
 * purpose of this documentation is to clarify the actual individual
 * requirements.
 *
 * This site presents you with the documentation for each function
 * that you need to implement broken down by the file that they exist
 * in. Please go to the <b>Files</b> tab and click on the file you wish to
 * get more information about and then click on that file. An
 * explanation of each function implemented in that file will be
 * displayed.
 **/

/**
 * @file con4.c contains the main function which is the entry point into the 
 * application and manages the main memory.
 **/

/**
 * the entry point into the game. You should display the main menu and 
 * respond to user requests.
 *
 * The main menu should look like this: 
 * Welcome to connect 4
 *  \n\--------------------
 * 1. Play Game
 * 2. Display High Scores
 * 3. Quit
 * Please enter your choice:
 *
 * This menu should also be redisplayed when the program returns from 
 * running an option.
 **/
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

    /* with each of the comments below, insert the code that performs
     * this function 
     */

    /* initialise the scoreboard */

    /*display menu and get menu choice until the user chooses to quit */
	do
	{
		displayMenu();

		fgets(choice, INPUT_SIZE + 2, stdin);
		
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
			case 1:
				play_game(&human_player, &computer_player);
				break;

			case 2:
				printf("Show High Score\n\n");
				break;

			case 3:
				printf("Quit Game\n\n");
				break;

			default:
				printf("Invalid Input.\n\n");
		}
	}
	while (menuChoice != 3);

	    /* play a game option */

		    /* if there was not a draw, add player to the scoreboard in
		     * order by number of tokens in play
		     */

		    /* let the user know who won */

		    /* if there was a draw, alert the user to this fact */

		/* display the scoreboard option */

		/* quit the program option */
    return EXIT_SUCCESS;
}
