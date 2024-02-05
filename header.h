/* Name: Genevieve Kochel
Date: October 14th, 2023
Description: This program will play the game of Yahtzhee
Purpose: This file contains all of the function prototypes and #includes and #defines for the program */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>

int print_game_menu(void);
void print_rules(void);
void roll_dice(int dice_arr[], int size);
void re_roll_dice(int dice_arr[], int num_dice_roll_again);
void print_dice(int dice_arr[], int size, int roll_count);
int combo_used_before(int player_scorecard[], int roll_combo);
int is_combo_valid(int roll_combo, int frequency_table[], int size);
void update_scorecard(int roll_combo, int player_scorecard[], int points_earned);
int calculate_roll_points(int combo_valid, int roll_combo, int frequency_table[], int size);
int calculate_score(int scorecard_arr[], int size); // only evaluates scorecard 
void update_frequency_table(int dice_arr[], int frequency_table[], int size_dice_arr);
void reset_frequency_table(int frequency_table[], int size);
int print_and_get_combo(void);
void play_turn(int scorecard_arr[], int player_num);


