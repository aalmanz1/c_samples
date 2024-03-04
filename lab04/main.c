/*
Author: Alex Almanza
Professor Jeff Shafer
ECPE 170
15 February 2021
*/

#include "functions.h"

int main() {
	FILE *fptr;
	char filename[100];
	char **grid = build_grid();
	printf("--------Welcome to Sudoku--------\n");
	printf("Rules: Fill the 9x9 square such that each row, column,\n"
                "or block contains all of the numbers 1-9\n\n"
                "Enter the game file name to load: ");
	
	scanf("%s", filename);
	printf("Loading game file %s%s", filename, "\n");
	fptr = fopen(filename, "r");

	fill_grid(grid, fptr);
	play_sudoku(grid);

	fclose(fptr);	
	delete_grid(grid);
	return 0;
}
