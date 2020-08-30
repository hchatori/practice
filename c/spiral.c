#include <stdio.h>
#include <stdlib.h>

/*
	Example: 
	size = 5

	1  2  3  4  5
	16 17 18 19 6
	15 24 25 20 7
	14 23 22 21 8
    13 12 11 10 9

*/

enum direction{Right, Down, Left, Up};

void spiral(int size) {
	// Allocate memory for the spiral.
	int** spiral = (int**)calloc(size, sizeof(int*));
	for (int i = 0; i < size; i++) {
		spiral[i] = (int*)calloc(size, sizeof(int));
	}

	// Populate the spiral.
	// If the next index value is not 0, change directions.

	int row = 0;
	int col = 0;
	enum direction d = Right;
	for (int n = 1; n <= size*size; n++) {
		spiral[row][col] = n;
		switch (d) {
		case Right: 
			col++;
			if (col+1 == size || spiral[row][col+1] != 0) { 
				d++;
			}
			break;
		case Down:
			row++;
			if (row+1 == size || spiral[row+1][col] != 0) {
				d++;
			}
			break;
		case Left:
			col--;
			if (col-1 == -1 || spiral[row][col-1] != 0) {
				d++;
			}
			break;
		case Up:
			row--;
			if (row-1 == -1 || spiral[row-1][col] != 0) {
				d++;
			}
			break;
		}
		d = d % 4;
	}

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			printf("%d\t", spiral[i][j]);
		}
		printf("\n");
	}

	// Free memory.
	for (int i = 0; i < size; i++) {
		free(spiral[i]);
	}
	free(spiral);
}

int main() {
	int size = 4;
	spiral(size);

	return 0;
}