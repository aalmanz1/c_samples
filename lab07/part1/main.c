#include <stdio.h>
#include <stdint.h>

#define ROWS 2
#define COLS 3


void traverse_2D();
void traverse_3D();
int sumarrayrows(int a[ROWS][COLS]);
int sumarraycols(int a[ROWS][COLS]);


int main() 
{
	printf("----------2D ARRAY of size [3][5]----------\n");
	traverse_2D();
	printf("\n----------3D ARRAY of size [3][5][3]----------\n");
	traverse_3D();
	//int a[ROWS][COLS];
	//printf("sumarrayrows: %d\n", sumarrayrows(a));
	//printf("sumarraycols: %d\n", sumarraycols(a));
}


void traverse_2D()
{
	uint32_t array[3][5];
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 5; j++) {
			printf("Memory address at index [%d][%d]: %p\n", i, j, &array[i][j]);
		}
	}
}


void traverse_3D()
{
	uint32_t array[3][5][3];
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 5; j++) {
			for (int k = 0; k < 3; k++) {
				printf("Memory address at index [%d][%d][%d]: %p\n", i, j, k, &array[i][j][k]);
			}
		}
	}
}


int sumarrayrows(int a[ROWS][COLS])
{
	int i, j, sum = 0;
	for (i = 0; i < ROWS; i++)
		for (j = 0; j < COLS; j++){
			printf("index [%d][%d]\n", i, j);
			sum += a[i][j];
		}
	return sum;
}


int sumarraycols(int a[ROWS][COLS])
{
	int i, j, sum = 0;
	for (j = 0; j < COLS; j++)
		for (i = 0; i < ROWS; i++) {
			printf("index [%d][%d]\n", i, j);
			sum += a[i][j];
		}
	return sum;
}