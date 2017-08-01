/*
 * Laicode_Move0ToRightWithOrder.cpp
Given an array of integers, move all the 0s to the right end of the array.

The relative order of the elements in the original array need to be maintained.

Assumptions:

The given array is not null.
Examples:

{1} --> {1}
{1, 0, 3, 0, 1} --> {1, 3, 1, 0, 0}
 */

#include <vector>

using namespace std;

vector<int> moveZero(vector<int> array) {
	// use slow pointer and fast pointer
	// if they are both not 0, copy fast to slow
	// if fast is 0, keep fast going
	int slow = 0, fast = 0;
	while (fast < array.size()) {
		if (array[fast] != 0) array[slow++] = array[fast++];
		else fast++;
	}
	while (slow < array.size()) array[slow++] = 0;
	return array;
}



