#include <stdio.h>
#include <stdlib.h>

int smallestNumNotInList(int* nums, int sizeOfNums) {
	if (sizeOfNums == 0) {
		return 0;
	}

	int i = 0;
	for (int j = 0; j <= nums[sizeOfNums-1]; j++) {
		if (nums[i] != j) {
			return j;
		}
		i++;
	}
	
	return nums[i] + 1;
}


int main() {

	// Example 1: Answer should be 0.
	// int sizeOfNums = 4;

	// int* nums = (int*)malloc(sizeOfNums * sizeof(int));
	// nums[0] = 2;
	// nums[1] = 3;
	// nums[2] = 4;
	// nums[3] = 5;

	// Example 2: Answer should be 3.
	// int sizeOfNums = 6;

	// int* nums = (int*)malloc(sizeOfNums * sizeof(int));
	// nums[0] = 0;
	// nums[1] = 2;
	// nums[2] = 4;
	// nums[3] = 6;
	// nums[4] = 8;
	// nums[5] = 10; 

	// Example 3: Answer should be 7.
	// int sizeOfNums = 10;

	// int* nums = (int*)malloc(sizeOfNums * sizeof(int));
	// nums[0] = 0;
	// nums[1] = 1;
	// nums[2] = 2;
	// nums[3] = 3;
	// nums[4] = 4;
	// nums[5] = 5;
	// nums[6] = 6;
	// nums[7] = 8;
	// nums[8] = 9;
	// nums[9] = 10;

	// Example 4: Answer should be 6.
	// int sizeOfNums = 9;

	// int* nums = (int*)malloc(sizeOfNums * sizeof(int));
	// nums[0] = 0;
	// nums[1] = 1;
	// nums[2] = 2;
	// nums[3] = 3;
	// nums[4] = 4;
	// nums[5] = 5;
	// nums[6] = 7;
	// nums[7] = 8;
	// nums[8] = 9;

	// Example 5: Answer should be 1073741800.
	int sizeOfNums = 1073741800;
	int* nums = (int*)malloc(sizeOfNums * sizeof(int));

	int i = 0;
	int n = 0;
	while (i < sizeOfNums) {
		if (i == 1073741800) {
			n++;
		}

		nums[i] = n;
		i++;
		n++;
	}

	int answer = smallestNumNotInList(nums, sizeOfNums);

	printf("Smallest Number: %d\n", answer);

	free(nums); 

	return 0;
}