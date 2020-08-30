#include <stdio.h>
#include <stdlib.h>

struct Map {
	int numIslands;
	int areaOfLargestIsland;
};

enum direction{Right, Down, Left, Up};

void islandsInMap(int** map, int n, int m, struct Map *m1) {
	// Step 1: Traverse all values in map until I find a 1. 
	// Step 2: If I find a 1, currArea++ and change the 1 to 2. Then, check 
	// the values surrounding '2' (right, down, left, up) for other 1s. 
	// If I find another 1, currArea++ and change 1 to 2. If I don't find 
	// another 1, but I find 2 instead, go to the 2 and continue. When I 
	// come across a value where all surrounding values are either all 0 or 
	// all 2s, numIslands++ and if currArea > largestArea, update 
	// largestArea = currArea.
	int numIslands = 0;
	int currArea = 0; 
	int largestArea = 0; 
	int x = 0;
	int y = 0;
	int checked = 0;
	int numTwos = 0; 
	enum direction d = Right;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == 1) {
				currArea++;
				map[i][j] = 2;
				while(1) {
					// When current value and all surrounding values are 2,
					// break.
					if (map[x][y] == 2 && map[x][y+1] == 2 && map[x+1][y] == 2 && map[x][y-1] == 2 && map[x-1][y] == 2) {
						break;
					}
					// When all values surrounding current value are 0, break.
					if (map[x][y+1] == 0 && map[x+1][y] == 0 && map[x][y-1] == 0 && map[x-1][y] == 0) {
						break;
					}
					// checked++;
					switch (d) {
					case Right:
						if (y == n || map[x][y+1] <= 0) {
							d++;
						}
						if (map[x][y+1] == 1) {
							y++;
							currArea++;
							map[x][y] = 2;
							d = 0;
						} 
						if (map[x][y+1] == 2) {
							if (d >= 3 && numTwos > 0) {
								map[x][y] = -1;
								y++;
								d = 0;
								numTwos = 0;
							}
							numTwos++;
							d++;
						}
						break;
					case Down:
						if (x == m || map[x+1][y] <= 0) {
							d++;
						}
						if (map[x+1][y] == 1) {
							x++;
							currArea++;
							map[x][y] = 2;
							d = 0;
						}
						if (map[x+1][y] == 2) {
							if (d >= 3 && numTwos > 0) {
								map[x][y] = -1;
								x++;
								d = 0;
								numTwos = 0;
							}
							numTwos++;
							d++;
						}
						break;
					case Left:
						if (y < 0 || map[x][y-1] <= 0) {
							d++;
						}
						if (map[x][y-1] == 1) {
							y--;
							currArea++;
							map[x][y] = 2;
							d = 0;
						}
						if (map[x][y-1] == 2) {
							if (d >= 3 && numTwos > 0) {
								map[x][y] = -1;
								y--;
								d = 0;
								numTwos = 0;
							}
							numTwos++;
							d++;
						}
						break;
					case Up:
						if (x < 0 || map[x-1][y] <= 0) {
							d++;
						}
						if (map[x-1][y] == 1) {
							x--;
							currArea++;
							map[x][y] = 2;
							d = 0;
						}
						if (map[x-1][y] == 2) {
							if (d >= 3 && numTwos > 0) {
								map[x][y] = -1;
								x--;
								d = 0;
								numTwos = 0;
							}
							numTwos++;
							d++;
						}
						break;
					}
				}
			}
		}
	}
	m1->areaOfLargestIsland = largestArea;
	m1->numIslands = numIslands;

	// Edge case:
	if (numIslands == 0) {
		m1->areaOfLargestIsland = -1;
	}
}

int main () {
	/* Example 1: Answer should be 3, 15.
	   [[1, 1, 1, 0, 0, 0, 0, 0, 0, 0],
		[1, 1, 1, 1, 0, 0, 0, 0, 0, 0],
		[1, 1, 1, 0, 1, 1, 0, 0, 0, 1],
		[1, 1, 0, 0, 1, 1, 1, 0, 1, 1],
		[1, 1, 0, 0, 1, 0, 0, 0, 1, 1],
		[1, 0, 0, 0, 1, 1, 0, 0, 1, 0],
		[0, 0, 0, 0, 1, 1, 1, 0, 1, 0]]
	*/
	int n = 7;
	int m = 10;
	int** map = (int**)malloc(n * sizeof(int*));

	for (int i = 0; i < n; i++) {
		map[i] = (int*)calloc(m, sizeof(int));
	}
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

	struct Map m1;
	islandsInMap(map, n, m, &m1);
	printf("Number of islands on the map: %d\n", m1.numIslands);
	printf("Area of the largest island: %d\n", m1.areaOfLargestIsland);

	// Print the map.
	printf("Map:\n\n");
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			printf("%d ", map[i][j]);
		}
		printf("\n");
	}
	printf("\n");

	for (int i = 0; i < n; i++) {
		free(map[i]);
	}
	free(map);

	return 0;
}

/*
		[X, X, X, 0, 0, 0, 0, 0, 0, 0],
		[X, X, X, X, 0, 0, 0, 0, 0, 0],
		[X, X, X, 0, X, X, 0, 0, 0, X],
		[X, X, 0, 0, X, X, X, 0, X, X],
		[X, X, 0, 0, X, 0, 0, 0, X, X],
		[X, 0, 0, 0, X, X, 0, 0, X, 0],
		[0, 0, 0, 0, X, X, X, 0, X, 0]   
*/