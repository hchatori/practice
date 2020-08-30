#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int changeIslandBFS(int** map, int numRows, int numCols, int coordinate, int islandNum) {
	// Queue:
	int* queue = (int*)malloc((numRows*numCols) * sizeof(int));
	int front = 0;
	int end = 0;
	int numsInQueue = 1;
	queue[end] = coordinate;
	int row;
	int col;
	int newCoordinate = 0;
	int currArea = 0;

	while (numsInQueue != 0) {
		row = queue[front] / numCols;
		col = queue[front] % numCols;

		// Check right:
		if (col+1 < numCols && map[row][col+1] == 1) {
			newCoordinate = (row*numCols) + (col+1);
			end++;
			queue[end] = newCoordinate;
			numsInQueue++;
		}
		// Check down:
		if (row+1 < numRows && map[row+1][col] == 1) {
			newCoordinate = ((row+1)*numCols) + col;
			end++;
			queue[end] = newCoordinate;
			numsInQueue++;
		}
		// Check left:
		if (col-1 >= 0 && map[row][col-1] == 1) {
			newCoordinate = (row*numCols) + (col-1);
			end++;
			queue[end] = newCoordinate;
			numsInQueue++;
		}
		// Check up:
		if (row-1 >= 0 && map[row-1][col] == 1) {
			newCoordinate = ((row-1)*numCols) + col;
			end++;
			queue[end] = newCoordinate;
			numsInQueue++;
		}

		if (map[row][col] == 1) {
			currArea++; 
		}
		
		map[row][col] = islandNum;
		front++;
		numsInQueue--;
	}
	free(queue);
	return currArea;
}

int largestIslandArea(int**map, int numRows, int numCols, int numIslands) {
	int largestArea = 0;
	int islandAreas[numIslands-1];
	memset(islandAreas, 0, sizeof(islandAreas));

	for (int i = 0; i < numRows; i++) {
		for (int j = 0; j < numCols; j++) {
			if (map[i][j] > 0) {
				islandAreas[map[i][j]-2]++;
			}
		}
	}
	for (int i = 0; i < (numIslands-1); i++) {
		if (islandAreas[i] > largestArea) {
			largestArea = islandAreas[i];
		}
	}
	return largestArea;
}

int changeIslands(int** map, int numRows, int numCols) {
	int coordinate = 0;
	int islandNum = 2;
	int largestArea = 0; 

	for (int i = 0; i < numRows; i++) {
		for (int j = 0; j < numCols; j++) {
			if (map[i][j] == 1) {
				coordinate = (i*numCols) + j;
				int currArea = changeIslandBFS(map, numRows, numCols, coordinate, islandNum);
				printf("Current Area: %d\n", currArea);
				islandNum++; 
				if (currArea > largestArea) {
					largestArea = currArea;
				}
			}
		}
	}
	printf("Total Number of Islands: %d\n", islandNum-2);	
	// int largestArea = largestIslandArea(map, numRows, numCols, islandNum);
	// printf("The largest island's area is: %d\n", largestArea);
	return largestArea;
}

int main () {
	/* Example 1: 
	   [[1, 1, 1, 0, 0, 0, 0, 0, 0, 0],
		[1, 1, 1, 1, 0, 0, 0, 0, 0, 0],
		[1, 1, 1, 0, 1, 1, 0, 0, 0, 1],
		[1, 1, 0, 0, 1, 1, 1, 0, 1, 1],
		[1, 1, 0, 0, 1, 0, 0, 0, 1, 1],
		[1, 0, 0, 0, 1, 1, 0, 0, 1, 0],
		[0, 0, 0, 0, 1, 1, 1, 0, 1, 0]]
	*/
	int numRows = 7;
	int numCols = 10;
	int** map = (int**)malloc(numRows * sizeof(int*));

	for (int i = 0; i < numRows; i++) {
		map[i] = (int*)calloc(numCols, sizeof(int));
	}

	// int map[numRows][numCols];

	map[0][0] = 1;
	map[0][1] = 1;
	map[0][2] = 1;

	map[1][0] = 1;
	map[1][1] = 1;
	map[1][2] = 1;
	map[1][3] = 1;

	map[2][0] = 1;
	map[2][1] = 1;
	map[2][2] = 1;
	map[2][4] = 1;
	map[2][5] = 1;
	map[2][9] = 1;

	map[3][0] = 1;
	map[3][1] = 1;
	map[3][4] = 1;
	map[3][5] = 1;
	map[3][6] = 1;
	map[3][8] = 1;
	map[3][9] = 1;

	map[4][0] = 1;
	map[4][1] = 1;
	map[4][4] = 1;
	map[4][8] = 1;
	map[4][9] = 1;

	map[5][0] = 1;
	map[5][4] = 1;
	map[5][5] = 1;
	map[5][8] = 1;

	map[6][4] = 1;
	map[6][5] = 1;
	map[6][6] = 1;
	map[6][8] = 1;

	/* Example 2:
		[[1, 1, 1, 1, 0],
		 [1, 1, 0, 1, 0],
		 [1, 0, 0, 0, 0]
		]
	*/

	// int numRows = 3;
	// int numCols = 5;
	// int** map = (int**)malloc(numRows * sizeof(int*));

	// for (int i = 0; i < numRows; i++) {
	// 	map[i] = (int*)calloc(numCols, sizeof(int));
	// }

	// map[0][0] = 1;
	// map[0][1] = 1;
	// map[0][2] = 1;
	// map[0][3] = 1;
	// map[1][0] = 1;
	// map[1][1] = 1;
	// map[1][3] = 1;
	// map[2][0] = 1;

	printf("Map Before:\n\n");
	for (int i = 0; i < numRows; i++){
		for (int j = 0; j < numCols; j++){
			printf("%d\t", map[i][j]);
		}
		printf("\n");
	}
	printf("\n");

	int largestArea = changeIslands(map, numRows, numCols);
	printf("The largest island's area is: %d\n", largestArea);

	printf("Map After:\n\n");
	for (int i = 0; i < numRows; i++){
		for (int j = 0; j < numCols; j++){
			printf("%d\t", map[i][j]);
		}
		printf("\n");
	}
	printf("\n");

	for (int i = 0; i < numRows; i++) {
		free(map[i]);
	}
	free(map);

	return 0;
}