/*
Author: Alex Almanza
Professor Jeff Shafer
ECPE 170
15 February 2021
*/

#include "functions.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

// N is very simply used whenever the grid's 'row' or 'col'
// need to be accessed, as it will always be 9.
#define N 9

// UNASSIGNED is set to the character '0' to simplify checking
// for empty spaces
#define UNASSIGNED '0'


// utility function to print a formatted grid
void print_grid(char **grid) {
	int counter = 0;
	printf("    1 2 3   4 5 6   7 8 9\n");
	printf("  |-----------------------|\n");
	for (int i = 0; i < N; i++) {
		counter++;
		printf("%d | ", counter);
		for (int j = 0; j < N; j++) {
			if (j == 3 || j == 6)
				printf("| ");
			printf("%c ", grid[i][j]);
		}
		printf("|");
		if (i == 2 || i == 5)
			printf("\n  |-----------------------|");
		printf("\n");
	}
	printf("  |-----------------------|\n\n");
}


// function to fill array with values taken from file
void fill_grid(char **grid, FILE *f) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			grid[i][j] = fgetc(f);
			if (grid[i][j] == '\n') {
				grid[i][j] = fgetc(f);
			}
		}
	}
}


// function to allocate space for array
char **build_grid() {
	char **array;
	array = (char **)malloc(sizeof(char *)*N);
	for(int i = 0; i < N; i++)
		array[i] = (char *)malloc(sizeof(char)*N);
	return array;
}


// function to free array pointer after use
void delete_grid(char **grid) {
	for (int i = 0; i < N; i++) {
		free(grid[i]);
	}
	free(grid);
}

//////////////////////////////////////////////////////////////////
////// used_in_row, used_in_col, used_in_box //////
/* functions to validate user input. Checks if a value exists */
/* in the current row, column, and box, respectively */
bool used_in_row(char **grid, int row, char num) {
	for (int col = 0; col < N; col++) {
		if (grid[row][col] == num) {
			return true;
		}
	}
	return false;
}


bool used_in_col(char **grid, int col, char num) {
	for (int row = 0; row < N; row++) {
		if (grid[row][col] == num) {
			return true;
		}
	}
	return false;
}


bool used_in_box(char **grid, int row_start, int col_start, char num) {
	for (int row = 0; row < 3; row++) {
		for (int col = 0; col < 3; col++) {
			if (grid[row + row_start][col + col_start] == num) {
				return true;
			}
		}
	}
	return false;
}

// just a utility function to call all verification functions
bool verify(char **grid, int row, int col, char num) {
	return !used_in_row(grid, row, num) 
		&& !used_in_col(grid, col, num) 
		&& !used_in_box(grid, row - row % 3, col - col % 3, num);
}


// utility function to count number of 0s (UNASSIGNED) that are in
// the current puzzle file.
int count_zeroes(char **grid) {
	int counter = 0;
	for (int row = 0; row < N; row++) {
		for (int col = 0; col < N; col++) {
			if (grid[row][col] == UNASSIGNED) {
				counter++;
			}
		}
	}
	return counter;
}


// primary game function
void play_sudoku(char **grid) {
	int user_row, user_col;
	char user_value;
	int counter = count_zeroes(grid);

	// game loop. Prompts repeat so long as there are 
	// empty spaces still on the grid.
	while (counter > 0) {
		printf("Current puzzle has %d unsolved items\n", counter);
		printf("\n");
		print_grid(grid);

		// one subtracted from inputted row/col for array logic
		printf("Enter (row col value) to solve a square, or Ctrl+C to exit: ");
		scanf("%d %d %c", &user_row, &user_col, &user_value);
		user_row -= 1;
		user_col -= 1;

		if (user_row > 8 || user_row < 0 || user_col > 8 || user_col < 0) {
			printf("\nError! Row and Column must be greater than 0 and less than 10.\n");
		}

		// if user space is empty and input is valid, assign that space
		// to user_value and mark counter down by one
		if (grid[user_row][user_col] == UNASSIGNED && verify(grid, user_row, user_col, user_value)) {
			grid[user_row][user_col] = user_value;
			counter -= 1;
		}
		else {
			printf("Try again! That value does not work here.\n");
		}
	}
	printf("CONGRATULATIONS!");
}
