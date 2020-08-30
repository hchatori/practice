#include <stdio.h>
#include <stdlib.h>

// Figure out the logarithmic solution. 

int smallestNumNotInList(int* nums, int sizeOfNums) {
	// Edge cases:
	if (sizeOfNums == 0) {
		return 0;
	}
	if (nums[0] != 0) {
		return 0;
	}
	if (nums[sizeOfNums-1] - nums[0] == sizeOfNums-1) {
		return nums[sizeOfNums-1] + 1;
	}

	// If the difference between two consecutive digits in nums is greater than
	// 1, we know that for the first such instance, the number that is one
	// greater than the first digit is our answer. For example, given 
	// a = [0, 1, 2, 4, 5], the difference between 2 and 4 is greater than 1, so
	// we know the answer is 3.

	int beg = 0;
	int mid = 0;
	int currSize = sizeOfNums; 
	int leftSize = 0;
	int rightSize = 0; 
	while (currSize > 1) {
		// Find the mid:
		if (currSize % 2 == 0) {
			mid = (currSize/2) + beg;
		} else {
			mid = ((currSize + 1)/2) + (beg-1);
		}

		currSize = mid - beg;

		if (nums[mid] <= mid) {
			currSize = sizeOfNums - (currSize + beg);
			beg = mid; 
			continue;
		} 
	}
	return nums[mid-1] + 1;
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
	printf("Smallest Missing Number: %d\n", answer);

	free(nums); 

	return 0;
}