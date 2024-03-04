#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

// define functions
void print_grid(char **grid);
void fill_grid(char **grid, FILE *f);
char **build_grid();
void delete_grid(char **grid);
bool used_in_row(char **grid, int row, char num);
bool used_in_col(char **grid, int col, char num);
bool used_in_box(char **grid, int row_start, int start_col, char num);
bool verify(char **grid, int row, int col, char num);
int count_zeroes(char **grid);
void play_sudoku(char **grid);

#endif
