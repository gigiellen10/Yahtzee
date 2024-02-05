/* Name: Genevieve Kochel
Date: October 14th, 2023
Description: This program will play the game of Yahtzhee
Purpose: This file contains all of the function headers for the program */

#include "header.h"


/* Function: int print_game_menu ()
 * Date Created: October 15th
 * Date Last Modified: October 15th
 * Description: Prints yahtzee game menu and prompts user to enter an option 1-3. Prints error message
 * and prompts user again if invalid input entered.
 * Input parameters: None.
 * Returns: Returns user_selection (1-3) which determines what portion of the menu is selected in main.
 * Preconditions: <stdio.h> must be included in the header to allow printf and scanf.
 * Postconditions: Return value of this function must control the switch statement for what each menu option does;
 * function must be called in main and assigned to variable controlling switch statement to do this.
 ************************************************************/
int print_game_menu(void) 
{
	
	int user_selection = 0;
	do 
	{
		printf("\nWELCOME TO YAHTZEE! PLEASE SELECT AN OPTION\n\n"
			"1. Print Game Rules\n"
			"2. Play Game\n"
			"3. Exit Game\n"
			"Enter your selection here: ");

		scanf("%d", &user_selection);

		if (user_selection < 0 || user_selection > 3)
		{
			system("cls");
			printf("\nTry again. Please enter a valid menu selection.\n");
		}

	} while (user_selection < 0 || user_selection > 3); // prompts user to enter valid menu selection if input outside of 1-3

	return user_selection;
}


/* Function: void print_rules ()
 * Date Created: October 15th
 * Date Last Modified: October 15th
 * Description: Prints game rules of yahtzee to screen.
 * Input parameters: None (void).
 * Returns: None (void).
 * Preconditions: The user must have selected to print game rules. <stdio.h> must be included to allow printf().
 * Postconditions: Function must be called in first case of switch statement (1 corresponds to user selecting to print
 * the rules of the game). Must go back to displaying main game menu after this function is called. 
 ************************************************************/
void print_rules(void)
{
	system("cls");
	printf("Hello players! The rules are simple: get more points than your opponent.\n"
		"There are 13 rounds. Each round, each player will each get a turn. On thier turn, they may\n"
		"roll 5 dice up to 3 times. The scorecard used for Yahtzee is composed of two sections\n"
		"An upper section and a lower section. A total of thirteen scoring combinations are\n" 
		"divided amongst the sections. The upper section consists of boxes scored by summing the\n"
		"values of the corresponding boxes. Once a player has chosen to score a box, it may not be\n" 
		"changed and the combination is no longer in play for future rounds.If thier sum of the scores\n"
		"in the upper section is greater than or equal to 63, then 35 more points are added to the\n"
		"players overall score as a bonus. The lower section contains a number of poker-like combinations.\n");
}

/* Function: void roll_dice (int dice_arr[], int size)
 * Date Created: October 17th
 * Date Last Modified: October 17th
 * Description: Rolls 5 dice and generates a random number 1-6. Fills each element of dice array with random number.
 * Input parameters: Array of type int (dice array), size of dice array.
 * Returns: None (void).
 * Preconditions: The dice array must be initialized and srand() must be called in main. 
 * Postconditions: Each element of the dice array must be filled with a random number 1-6.
 ************************************************************/
void roll_dice(int dice_arr[], int size)
{
	int index = 0;

	for (; index < size; index++)
	{
		
		dice_arr[index] = rand() % 6 + 1;

	}
}

/* Function: void print_dice(int dice_arr[], int size)
 * Date Created: October 18th 2023
 * Date Last Modified: October 18th 2023
 * Description: This function prints all of the dice in the dice array. 
 * Input parameters: Dice array, size of dice array and roll count.
 * Returns: None, void.
 * Preconditions: User must have rolled before calling this function, and dice array must be filled with values other than 0.
 * Postconditions: The dice from the dice array must be printed to the screen. 
 ************************************************************/
void print_dice(int dice_arr[], int size, int roll_count)
{
	int index = 0;
	
	printf("\n*********** These are your dice for roll #%d ************\n", roll_count);
	for (; index < size; index++)
	{
		printf("\nDice %d: %d\n", index + 1, dice_arr[index]);

	}

}

/* Function: void re_roll_dice ()
 * Date Created: October 17th
 * Date Last Modified: October 17th
 * Description: Re-rolls dice of user's choice by generating a random number 1-6 and over writing index of dice - 1 
 * because dice # and index number are off by 1.
 * Input parameters: Dice array, number of dice user wants to re-roll. 
 * Returns: None (void).
 * Preconditions: <time.h> and <stdlib.h> must be included, user must have input a dice number 1-5 to re-roll (must 
 * validate this), array for dice must be defined in main. 
 * Postconditions: After function call, in dice array, the index of dice # - 1 should be altered 
 to a new random number between 1-6.
 ************************************************************/

void re_roll_dice(int dice_arr[], int num_dice_roll_again)
{
	int count = 0, dice_num = 0, dice_already_rerolled[] = { 0, 0, 0, 0, 0 };
	while (count < num_dice_roll_again)
	{
		do
		{

			printf("Please enter the die number you want to re-roll (1-5): "); // how to say "Please enter the 1st/2nd/3rd/4th/5th dice you want to re roll
			scanf("%d", &dice_num);

			if (dice_num < 0 || dice_num > 5)
			{
				printf("*** Invalid input! Please enter a dice 1-5. ***\n");
			}
			
			if (dice_already_rerolled[dice_num - 1] == 1)
			{
				printf("You've already re-rolled that dice! Please enter another dice to re-roll.\n");
			}

		} while (dice_num < 0 || dice_num > 5 || dice_already_rerolled[dice_num - 1] == 1);


		dice_arr[dice_num - 1] = rand() % 6 + 1;

		dice_already_rerolled[dice_num - 1] = 1;

		++count;

	}
	
	
	//if (num_dice_roll_again == 1)
	//{
	//	int dice1 = 0;
	//	scanf("%d", &dice1); // get input
	//	dice_arr[dice1] = rand() % 6 + 1;
	//}
	//if (num_dice_roll_again == 2)
	//{
	//	int dice1 = 0, dice2 = 0;
	//	scanf("%d%d", &dice1, &dice2); // get input
	//	dice_arr[dice1] = rand() % 6 + 1;
	//	dice_arr[dice2] = rand() % 6 + 1;
	//}
	//if (num_dice_roll_again == 3)
	//{
	//	int dice1 = 0, dice2 = 0, dice3 = 0;
	//	scanf("%d%d%d", &dice1, &dice2, &dice3); // get input
	//	dice_arr[dice1] = rand() % 6 + 1;
	//	dice_arr[dice2] = rand() % 6 + 1;
	//	dice_arr[dice3] = rand() % 6 + 1;
	//	
	//}
	//if (num_dice_roll_again == 4)
	//{
	//	int dice1 = 0, dice2 = 0, dice3 = 0, dice4 = 0;
	//	scanf("%d%d%d%d", &dice1, &dice2, &dice3, &dice4); // get input
	//	dice_arr[dice1] = rand() % 6 + 1;
	//	dice_arr[dice2] = rand() % 6 + 1;
	//	dice_arr[dice3] = rand() % 6 + 1;
	//	dice_arr[dice4] = rand() % 6 + 1;

	//}
	//if (num_dice_roll_again == 5)
	//{
	//	int dice1 = 0, dice2 = 0, dice3 = 0, dice4 = 0, dice5 = 0;
	//	scanf("%d%d%d%d%d", &dice1, &dice2, &dice3, &dice4, &dice5); // get input
	//	dice_arr[dice1] = rand() % 6 + 1;
	//	dice_arr[dice2] = rand() % 6 + 1;
	//	dice_arr[dice3] = rand() % 6 + 1;
	//	dice_arr[dice4] = rand() % 6 + 1;
	//	dice_arr[dice5] = rand() % 6 + 1;
	//}

}

/* Function: void update_scorecard(int roll_combo, int player_scorecard[], int points_earned)
 * Date Created: October 18th
 * Date Last Modified: October 18th
 * Description: This function updates the section of the scorecard 1-13 with the number of points the player earned for that
 * round.
 * Input parameters: Accepts the roll combo selection that the player selected to use, scorecard for that specific player
 * and the results of the calculate_roll_points () function.
 * Returns: None, void.
 * Preconditions: Roll combination to use (refers to the index of the scorecard that will be updated) must have been gotten from
 * user and checked for validity, results of points earned must have been calculated before function call. 
 * Postconditions: Must edit scorecard array for either player 1 or player 2, and update the correct index of 
 * the scorecard (depending on what combo) to reflect the number of points passed into the function. 
 ************************************************************/
void update_scorecard(int roll_combo, int player_scorecard[], int points_earned) // points_earned is result of calculate_roll_points ()
{

	player_scorecard[roll_combo] = points_earned; 

}

/* Function: int combo_used_before ()
 * Date Created: October 18th 2023
 * Date Last Modified: October 18th 2023
 * Description: Checks if player has used the entered combo before. 
 * Input parameters: Accepts the number of the roll combination that the user selected (result of print_and_get_roll_combo()) and
 * the scorecard array of the player who's turn it is.
 * Returns: 1 if combo has already been used by user. 0 if user hasn't used that combo yet. 
 * Preconditions: Must have gotten combo number from user before calling, via the print_and_get_roll_combo() function.
 * Postconditions: If value returned is 1, user must be re-prompted to enter another combo selection ** do while loop condition.
 ************************************************************/
int combo_used_before(int player_scorecard[], int roll_combo)
{
	if (player_scorecard[roll_combo] == -1)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}

/* Function: int is_combo_valid ()
 * Date Created: October 18th 2023
 * Date Last Modified: October 18th 2023
 * Description: Checks if they have the correct dice values to use the selected combo number. 
 * Input parameters: Accepts the number of the roll combination that the user selected (result of print_and_get_roll_combo()),
 * the frequency table array, and the size of the frequency table array.
 * Returns: 1 if user has dice values that satisfy that combo, 0 if user doesn't have dice values. 
 * Preconditions: Value returned by combo_used_before must be 0, indicating the combo hasn't been used before. 
 * Postconditions: Value returned by this function must be passed into calculate_roll_points() to determine the number of points 
 * user gets. If this function returns 0, user gets 0 points for that roll automatically. 
 ************************************************************/
int is_combo_valid(int roll_combo, int frequency_table[], int size)
{
	int combo_valid = 0; // returns 0 if combo is not valid

	/* Sum of Ones */
	if (roll_combo == 1 && frequency_table[1] >= 1) // user selected sum of ones and user had at least one dice with a 1
	{
		combo_valid = 1;
	}

	/* Sum of Twos */
	if (roll_combo == 2 && frequency_table[2] >= 1)
	{
		combo_valid = 1;
	}

	/* Sum of Threes */
	if (roll_combo == 3 && frequency_table[3] >= 1)
	{
		combo_valid = 1;
	}

	/* Sum of Fours */
	if (roll_combo == 4 && frequency_table[4] >= 1)
	{
		combo_valid = 1;
	}

	/* Sum of Fives */
	if (roll_combo == 5 && frequency_table[5] >= 1)
	{
		combo_valid = 1;
	}

	/* Sum of Sixes */
	if (roll_combo == 6 && frequency_table[6] >= 1) 
	{
		combo_valid = 1;
	}

	/* Three of a kind */

	if (roll_combo == 7)
	{
		int target = 0, index = 0;
		while (index < size && target != 3)
		{
			
				target = frequency_table[index];

			++index;
		}

		if (target == 3)
		{
			combo_valid = 1;
		}
		
	}

	/* Four of a kind */

	if (roll_combo == 8)
	{
		int target = 0, index = 0;
		while (index < size && target != 4)
		{

			target = frequency_table[index];

			++index;
		}

		if (target == 4)
		{
			combo_valid = 1;
		}

	}

	/* Full House */

	if (roll_combo == 9)
	{

		int index = 0, target2 = 0, target3 = 0;
		while (index < size && target2 != 2) // loops through frequency table and tries to find an element that has a 2
		{

			target2 = frequency_table[index];

			++index;
		}

		index = 0; // resets index back to 0 for next loop to find a 3 in the frequency array

		while (index < size && target3 != 3) // loops through frequency table and tries to find an element that has a 2
		{

			target3 = frequency_table[index];

			++index;
		}

		if (target2 == 2 && target3 == 3)
		{
			combo_valid = 1;
		}
	}

	/* Small Straight */

	if (roll_combo == 10)
	{
		int counter = 0, index = 0;
		while (counter != 4 && index < size)
		{
			if (frequency_table[index] >= 1)
			{
				++counter;
			}

			else
			{
				counter = 0;
			}

			++index;
		}

		if (counter == 4)
		{
			combo_valid = 1;
		}
	
	}

	/* Large Straight */
	if (roll_combo == 11)
	{
		int counter = 0, index = 0;
		while (counter != 5 && index < size)
		{
			if (frequency_table[index] >= 1)
			{
				++counter;
			}

			else
			{
				counter = 0;
			}

			++index;
		}

		if (counter == 5)
		{
			combo_valid = 1;
		}

	}

	/* Yahtzee */
	if (roll_combo == 12)
	{
		int target = 0, index = 0;
		while (index < size && target != 5) // loops through frequency table and sees if theres 5 of a kind in any of the elements
		{

			target = frequency_table[index];

			++index;
		}

		if (target == 5)
		{
			combo_valid = 1;
		}

	}

	/* Chance */
	if (roll_combo == 13)
	{
		combo_valid = 1;
	}

	return combo_valid;
}

/* Function: int calculate_roll_points ()
 * Date Created: October 18th
 * Date Last Modified: October 18th
 * Description: This function calculates the number of points earned by a player depending on a specific combo type
 * Input parameters: Accepts results of is_combo_valid (0 or 1), roll combination that user selected, frequency table array 
 * and size of frequency table array (14).
 * Returns: Number of points user earned for that turn
 * Preconditions: Must know results of is_combo_valid () before calling this function, user must have selected a
 * roll combination that they wanted to use prior.
 * Postconditions: If is_combo_valid is true (1), must calculate the number of points the user earned for the selected combo.
 * If is_combo_valid is false (0), returns 0 points for that combo selected.
 ************************************************************/
int calculate_roll_points(int combo_valid, int roll_combo, int frequency_table[], int size)
{
	int points_earned = 0, index = 1; // returns 0 if combo_valid is false (0)
	
	/* Sum of ones */
	if (combo_valid && roll_combo == 1)
	{
		points_earned = frequency_table[1];
	}

	/* Sum of twos */
	if (combo_valid && roll_combo == 2)
	{
		points_earned = frequency_table[2] * 2;
	}

	/* Sum of threes */
	if (combo_valid && roll_combo == 3)
	{
		points_earned = frequency_table[3] * 3;
	}

	/* Sum of fours */
	if (combo_valid && roll_combo == 4)
	{
		points_earned = frequency_table[4] * 4;
	}

	/* Sum of fives */
	if (combo_valid && roll_combo == 5)
	{
		points_earned = frequency_table[5] * 5;
	}

	/* Sum of sixes */
	if (combo_valid && roll_combo == 6)
	{
		points_earned = frequency_table[6] * 6;
	}

	/* Three of a kind */
	if (combo_valid && roll_combo == 7)
	{
		while (index < size)
		{
			points_earned = points_earned + (frequency_table[index] * index); // sums all dice values depending on frequency table
			
			++index;
		}
	}

	/* Four of a kind */
	if (combo_valid && roll_combo == 8)
	{
		while (index < size)
		{
			points_earned = points_earned + (frequency_table[index] * index); // sums all dice values depending on frequency table

			++index;
		}

	}

	/* Full house */
	if (combo_valid && roll_combo == 9)
	{
		points_earned = 25;
	}

	/* Small Straight */
	if (combo_valid && roll_combo == 10)
	{
		points_earned = 30;
	}

	/* Large Straight */
	if (combo_valid && roll_combo == 11)
	{
		points_earned = 40;
	}

	/* Yahtzee */
	if (combo_valid && roll_combo == 12)
	{
		points_earned = 50;
	}

	/* Chance */
	if (combo_valid && roll_combo == 13)
	{
		while (index < size)
		{
			points_earned = points_earned + (frequency_table[index] * index); // sums all dice values depending on frequency table

			++index;
		}
	}

	return points_earned;
}

/* Function: void calculate_and_display_score(int scorecard_arr[], int size, int player_number)
 * Date Created: October 18th 2023
 * Date Last Modified: October 18th 2023
 * Description: This function adds all of the elements of the scorecard array for a single player (call twice, 1 
 * for each player). It also factors in bonus points and adds them to the player's final score, if they got the bonus.
 * Input parameters: Scorecard array for singular player and size of scorecard array (14).
 * Returns: Void, none.
 * Preconditions: All 13 rounds of the game must have been played (meaning all elements of the scorecard array for both
 * player must have values other than -1 in them.
 * Postconditions: Value returned for player 1 and player 2 must be displayed, then compared to display the winner (if statements). 
 ************************************************************/
int calculate_score(int scorecard_arr[], int size) // only evaluates scorecard 
{
	int final_score = 0, index = 1, check_bonus = 0; // index is 1 initially so don't factor in -1 to score
	while (index < size)
	{
		final_score = final_score + scorecard_arr[index];
		++index;
	}

	while (index < 7)
	{
		check_bonus = check_bonus + scorecard_arr[index];

	} // add up all scores in elements corresponding to sum of 1-6 roll combos 
	
	if (check_bonus >= 63)
	{
		final_score = final_score + 63;
	}// calculate bonus, gets bonus if index 1-6 adds up to be larger or = than 63

	return final_score;
	
}

/* Function: void update_frequency_table(int dice_arr[], int frequency_table[], int size_dice_arr)
 * Date Created: October 18th 2023
 * Date Last Modified: October 18th 2023
 * Description: This function goes through the dice array and evaluates the values stored in each index. Depending on 
 * the value found in each index, the function goes to that corresponding index in the frequency table and adds 1. This
 * process repeats until the end of the dice array is reached. 
 * Input parameters: Accepts dice array and frequency table array, both of type int, and the size of the dice array.
 * Returns: None (void).
 * Preconditions: Dice array must be defined and a player must have rolled. 
 * Postconditions: Frequency table must be set back to 0 after player has completed thier turn for that round (after scorecard is
 * updated and right before players switch). 
 ************************************************************/
void update_frequency_table(int dice_arr[], int frequency_table[], int size_dice_arr)
{
	int index = 0;
	while (index < size_dice_arr)
	{
		frequency_table[dice_arr[index]] += 1;

		++index;
	}
}

/* Function: void reset_frequency_table (int frequency_table[], int size)
 * Date Created: October 18th
 * Date Last Modified: October 18th
 * Description: This function resets the frequency table back to zeros after the user has completed thier turn.
 * Input parameters: Accepts frequency_table[] array (type int) and the size of the frequency table array.
 * Returns: None, void.
 * Preconditions: Frequency table array must be defined and a player must have completed thier turn for that round.
 * Postconditions: Function must alter frequency table array to contain all zeros in all 7 elements of the array 
 * (index [0] will always have 0 because it is never used, because user cannot roll a 0). 
 ************************************************************/
void reset_frequency_table(int frequency_table[], int size) // resets frequency table to 0 at end of user turn
{
	int index = 0;
	for (; index < size; index++)
	{
		frequency_table[index] = 0;
	}

}

/* Function: int print_and_get_combo (void)
 * Date Created: October 18th 2023
 * Date Last Modified: October 18th 2023
 * Description: This function prompts the user to enter one of the dice combinations, displays choices and gets input.
 * Function continues to do this until user enters a valid number 1-13.
 * Input parameters: None, void.
 * Returns: Number corresponding to combination selection of user (1-13). 
 * Preconditions: <stdio.h> should be included in main. User should have selected 'Y' that they want to select 
 a combination to use for that roll, or the roll count should be == 3 to use this function.  
 * Postconditions: The combo_choice returned from this function should be used as an argument in is_combo_valid() function.
 ************************************************************/
int print_and_get_combo (void)
{
	int combo_choice = 0;
	
	do
	{
		printf("\n(1) Sum of One's\n"
			"(2) Sum of Two's\n"
			"(3) Sum of Three's\n"
			"(4) Sum of Four's\n"
			"(5) Sum of Five's\n"
			"(6) Sum of Six's\n"
			"(7) Three of-a-kind\n"
			"(8) Four of-a-kind\n"
			"(9) Full House\n"
			"(10) Small Straight\n"
			"(11) Large Straight\n"
			"(12) Yahtzee\n"
			"(13) Chance\n");
		printf("\nPlease enter a combination number 1-13: ");
		scanf("%d", &combo_choice); // get user combo choice 
		if (!(combo_choice > 0 && combo_choice < 14))
		{
			printf("\n*** Invalid input. Please try again ***\n");
		}

	} while (!(combo_choice > 0 && combo_choice < 14));

	return combo_choice;
}

/* Function: void play_turn (int scorecard_arr[], int player_num)
 * Date Created: October 23rd 2023
 * Date Last Modified: October 23rd 2023
 * Description: This function loops through a turn for a single player, adjusting the correct corresponding scorecard array.
 * Input parameters: Scorecard array of the player who's playing that turn, and the corresponding player number.
 * Returns: None, void.
 * Preconditions: User must have selected to play the game from the main menu, the scorecard array's for both players must be defined. 
 * Postconditions: Function must be called twice; once for each player. The array for the corresponding player's scorecard must be altered, and a score
 * other than -1 must be in the index corresponding to the combo they chose to use for that turn.
 ************************************************************/
void play_turn(int scorecard_arr[], int player_num)
{
	
	int print_game_menu_decision = 0, play_game = 0, menu_data = 0, rolls = 0;
	int dice_arr[5] = { 0, 0, 0, 0, 0 }, frequency_table[7] = { 0, 0, 0, 0, 0, 0, 0 },
		player1_scorecard[14] = { -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 },
		player2_scorecard[14] = { -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 };

	int num_dice_roll_again = 0, combo_choice = 0, is_combo_used = 0, is_combo_valid_input = 0,
		points_earned = 0, roll_count = 0; // note: is combo used is set to 1 by default
	char player_input = '\0';
	
	while (!(player_input == 'Y' || roll_count == 3))
	{
		if (roll_count == 0) /***************FIX ROLL DICE AND RE ROLL TO MATCH INDEX SIZE ***********/
		{

			printf("************** PLAYER %d ****************\n", player_num);
			printf("\nLets roll!!\n\n");
			system("pause"); // allow user to hit any key and roll dice
			roll_dice(dice_arr, 5); // invoke roll_dice function to get initial roll **************changed from 6 to 5 size
		}

		if (player_input == 'N') // if user does not want to use that roll for a combo
		{
			do
			{
				printf("\nHow many dice would you like to re-roll? Please enter a value 1-5: ");// ask how many dice they want to re-roll
				scanf("%d", &num_dice_roll_again); // get input

				if (!(num_dice_roll_again > 0 && num_dice_roll_again < 6))
				{
					printf("\n*** Invalid input. Please try again. ***\n");
				}

			} while (!(num_dice_roll_again > 0 && num_dice_roll_again < 6)); // validate number input



			re_roll_dice(dice_arr, num_dice_roll_again); // get dice values to re roll and re roll

		}

		++roll_count; // increment roll_count
		print_dice(dice_arr, 5, roll_count); // invoke print_dice() function


		do
		{
			printf("\nWould you like to use this roll for your combination? Please enter 'Y' or 'N': "); // prompt user if they want to use that roll for a combo
			scanf(" %c", &player_input);
			;
			if (!(player_input == 'Y' || player_input == 'N'))
			{
				printf("\n*** Invalid input. Please try again. ***\n");
			}

		} while (!(player_input == 'Y' || player_input == 'N')); // keep prompting as long as input isn't Y or N

	}

	update_frequency_table(dice_arr, frequency_table, 5); // update frequency table with dice roll

	do // changed to do while loop and is_combo_used = 0 initially now.
	{
		if (roll_count == 3 && player_input != 'Y')
		{
			printf("\nYou have rolled the maximum amount for this turn. You must select a combo.\n");
		}

		/* if input is yes or roll count is 3 */
		printf("\nWhat combination would you like to use this roll for?\n");// ask user what combo they want to use that roll for 

		combo_choice = print_and_get_combo();


		is_combo_used = combo_used_before(scorecard_arr, combo_choice);// call combo_used_before () and see if 1 or 0 

		if (is_combo_used == 1)
		{
			printf("\n!! Sorry, you already used that combination and may not use it again. Enter another. !!\n");
		}
	} while (is_combo_used == 1); // while the user has already used that combination, reprompts for combo number


	is_combo_valid_input = is_combo_valid(combo_choice, frequency_table, 7); //  make sure that user actually has that combo
	if (is_combo_valid_input == 0)
	{
		printf("\nSorry, you do not have that combo! You get 0 points for that roll.\n");
	}


	points_earned = calculate_roll_points(is_combo_valid_input, combo_choice, frequency_table, 7); // call  points_earned = roll_points () and pass in: the user input from previous loop, the frequency table and output number pts earned for roll
	if (points_earned != 0)
	{
		printf("\nYou earned %d points for that combination!\n", points_earned);

	}
	update_scorecard(combo_choice, scorecard_arr, points_earned); // call update_scorecard (), pass in: points_earned, scorecard array *for that user*
	reset_frequency_table(frequency_table, 7);// reset frequency table back to 0's
	
}
