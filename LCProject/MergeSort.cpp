/*
Given an array of integers, sort the elements in the array in ascending order. 
The merge sort algorithm should be used to solve this problem.
*/
// main function that calls merge_sort
// left: the left index of the sub vector
// right: the right index of the sub vector
// Time complexity is O(nlgn), space complexity is O(n)
// time complexity: at every layer it's O(n) and total O(logn) layers
#include <iostream>
#include <vector>
#include <climits>
#include "tc.h"
using namespace std;

vector<int> merge(vector<int> & lhs, vector<int> & rhs)
{
	vector<int> result;
	int i = 0, j = 0;
	while (i < lhs.size() || j < rhs.size())
	{
		int val1 = i < lhs.size() ? lhs[i] : INT_MAX;
		int val2 = j < rhs.size() ? rhs[j] : INT_MAX;
		if (val1 <= val2) result.push_back(lhs[i++]);
		else result.push_back(rhs[j++]);
	}
	return result;
}

vector<int> mergeSort_recursion(vector<int> & nums, int lhs, int rhs)
{
	vector<int> result;
	if (lhs == rhs)
	{
		result.push_back(nums[lhs]);
		return result;
	}
	int mid = lhs + (rhs - lhs) / 2;
	vector<int> left = mergeSort_recursion(nums, lhs, mid);
	vector<int> right = mergeSort_recursion(nums, mid + 1, rhs);
	result = merge(left, right);
	return result;
}


vector<int> mergeSort(vector<int> input)
{
	if (input.empty()) return input;
	return mergeSort_recursion(input, 0, input.size() - 1);
}

/*
int main(int argc, char* argv)
{
	int i, n = 15;
	vector<int> nums = generateTestcase(n);

	cout << "Before calling sort function" << endl;
	for (i = 0; i < n; i++)
	{
		cout << nums[i] << '\t';
	}
	cout << endl;

	nums = mergeSort(nums);

	cout << "After calling sort function" << endl;
	for (i = 0; i < n; i++)
	{
		cout << nums[i] << '\t';
	}
	cout << endl;

	system("pause");
}
*/




// Discuss
// 1. Could you use Merge Sort to sort a linked list? What is the time complexity if so?
// 2. similar problems - 
// 2.1 e.g., A1B2C3D4 - > ABCD1234  - only combine function is changed
// 2.2 (advanced topic) count-array problem

