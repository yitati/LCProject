/*
Given an array of integers, sort the elements in the array in ascending order. 
The quick sort algorithm should be used to solve this problem.
*/

#include <vector>
#include <iostream>

using namespace std;

// three areas 
// [lhs, i) - all elements smaller than pivot
// [i, j] - unknow area
// (j, rhs] - all elements greater or equal to pivot
void QuickSort(vector<int> & nums, int lhs, int rhs)
{
	if (lhs >= rhs) return;
	int lower = lhs, upper = rhs - 1;
	int pivot = nums[rhs];

	while (lower <= upper)
	{
		if (nums[lower] <= pivot) lower++;
		else if (nums[upper] > pivot) upper--;
		else
		{
			swap(nums[lower++], nums[upper--]);
		}
	}
	// out of loop we get lhs <= upper < lower <= rhs-1
	swap(nums[lower], nums[rhs]);
	QuickSort(nums, lhs, upper);
	// here is where we make it a smaller problem
	QuickSort(nums, lower+1, rhs);
}



