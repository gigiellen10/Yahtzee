/* Name: Genevieve Kochel
Date: October 14th, 2023
Description: This program will play the game of Yahtzhee
Purpose: This file controls the main game play of Yahtzhee, main function */

#include "header.h"

int main(void)
{
	int print_game_menu_decision = 0, play_game = 0, menu_data = 0, exit_game = 0, round_count = 0;
	int dice_arr[5] = { 0, 0, 0, 0, 0}, frequency_table[7] = { 0, 0, 0, 0, 0, 0, 0 }, 
		player1_scorecard[14] = { -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 }, 
		player2_scorecard[14] = { -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 }; // when add up scores,
	// start with 2nd index so don't accidentally factor in -1 at index [0] to addition****

	srand((unsigned int)time(NULL)); // call srand() so can fill dice array with random numbers 1-6

	while (exit_game == 0) // set exit_game = 1 if want to exit game program and return 0 at end of main
	{
		/*****************print menu section**************/
		do
		{
			menu_data = print_game_menu(); // print game menu, gets user input 1-3 and assign it to menu_data variable

			switch (menu_data)
			{
			case 1: // user selected to print game rules
				print_rules();
				do
				{
					printf("\nWould you like to go back to the main menu? Enter 1 for yes, 0 for no: ");
					scanf("%d", &print_game_menu_decision);
					if (print_game_menu_decision > 1 || print_game_menu_decision < 0)
					{
						system("cls");
						printf("\n*** Invalid input. Please try again. ***\n");
					}

				} while (print_game_menu_decision > 1 || print_game_menu_decision < 0);
				if (print_game_menu_decision == 0)
				{
					exit_game = 1;
				}

				system("cls");
				break;
			case 2: // user selected to start game
				print_game_menu_decision = 0; // exits "print game menu" loop and enters "play game" loop
				play_game = 1;
				break;

			case 3: // user selected to exit game
				print_game_menu_decision = 0;
				play_game = 0;
				exit_game = 1; // breaks out of ENTIRE game/ printing menu loop, only instance where breaks out of loop
				break;
			}

		} while (print_game_menu_decision == 1); // loop for printing game menu


		/************play game section****************/

		while (play_game == 1) // if want to exit game, set play_game = 0 -- ex: if players are done playing/someone has won
		{
			int num_dice_roll_again = 0, combo_choice = 0, is_combo_used = 1, is_combo_valid_input = 0,
				points_earned = 0, roll_count = 0; // note: is combo used is set to 1 by default
			char player1_input = '\0';
			
			while (round_count < 13)
			{
				
				/* PLAYER 1 TURN */
				system("cls");
				printf("\nROUND #%d\n", round_count + 1);
				play_turn(player1_scorecard, 1);
				if (round_count != 13)
				{
					printf("\nLet's move on to the next player!\n");
					system("pause");
				}


				/* PLAYER 2 TURN */
				system("cls");
				printf("\nROUND #%d\n", round_count + 1);
				play_turn(player2_scorecard, 2);
				if (round_count != 13)
				{
					printf("\nLet's move on to the next player!\n");
					system("pause");
				}
					
				++round_count;
			}

			play_game = 0; // escapes game play after 13 rounds

		} // end of play game loop, may want to escape if all 13 rounds have been completed -- print point results/winner after

		if (round_count == 13)
		{
			int calculate_score_player1 = 0, calculate_score_player2 = 0;
			calculate_score_player1 = calculate_score(player1_scorecard, 14); // call calculate_bonus FOR EACH USER --> pass in apllicable scorecard 
			calculate_score_player2 = calculate_score(player2_scorecard, 14);

			printf("\n****** Player 1's final score is: %d points ******\n", calculate_score_player1);
			printf("\n****** Player 2's final score is: %d points ******\n", calculate_score_player2); 

			if (calculate_score_player1 > calculate_score_player2)
			{
				printf("\nThe winner is player 1!!\n");
			}
			else
			{
				printf("\nThe winner is player 2!!\n");
			}

			int back_to_menu = 0;
			do
			{
				printf("\nWould you like to go back to the main menu? Print 1 if yes, 0 if no.\n"); // ask if wants to go back to main menu
				scanf("%d", &back_to_menu);
				system("cls");

				if (!back_to_menu)
				{
					exit_game = 1; // breaks out of entire menu loop and prints 0
				}
				if (back_to_menu < 0 || back_to_menu > 1)
				{
					printf("*** Sorry, that is invalid input. Please try again. ***\n");
				}

			} while (back_to_menu < 0 || back_to_menu > 1);
			system("cls");
		}

	} // end of entire program loop, only returns 0 when user chooses to exit program
	
	system("cls");
	printf("\nThanks for playing Yahtzee!! Goodbye.\n");

	return 0;
}