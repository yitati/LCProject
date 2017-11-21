/******************************************************************************
* Question: #34 Search For a Range
* company tag: LinkedIn
* Given an array of integers sorted in ascending order, find the starting and ending position of a given target value.
* Your algorithm's runtime complexity must be in the order of O(log n).
* If the target is not found in the array, return [-1, -1].

For example,
Given [5, 7, 7, 8, 8, 10] and target value 8,
return [3, 4].
*****************************************************************************/

#include <iostream>
#include <vector>

using namespace std;

// in binary search we can find lhs and rhs which are closest to the target number
// find one and expand to lhs and rhs
// time complexity is logN+k (k is the number of duplicates)
vector<int> searchRange(vector<int>& nums, int target) 
{
	vector<int> result(2, -1);
	int n = nums.size();
	if (n == 0) return result;
	int lhs = 0, rhs = n - 1;
	int mid = lhs + (rhs - lhs) / 2;

	while (lhs < rhs)
	{
		if (nums[mid] == target) break;
		else if (nums[mid] < target) lhs = mid + 1;
		else rhs = mid - 1;
		mid = lhs + (rhs - lhs) / 2;
	}

	if (nums[mid] != target) return result;
	lhs = mid;
	rhs = mid;
	while (lhs >= 0 && nums[lhs] == nums[mid]) lhs--;     // expand to left
	while (rhs <= n-1 && nums[rhs] == nums[mid]) rhs++;   // expand to right
	result[0] = lhs + 1;
	result[1] = rhs - 1;
	return result;
}

// serach first occurance which will finally located on lhs
int serachFirstOccurance(vector<int>& nums, int target, int lhs, int rhs)
{
	if (lhs > rhs) return -1;
	int mid;
	while (lhs < rhs)
	{
		mid = lhs + (rhs - lhs) / 2;
		if (nums[mid] >= target) rhs = mid;
		else lhs = mid + 1;
	}
	if (target == nums[lhs]) return lhs;
	return -1;
}

// find last occurance, which will finally locate on rhs
int serachLastOccurance(vector<int>& nums, int target, int lhs, int rhs)
{
	if (lhs > rhs) return -1;
	int mid;
	while (lhs + 1 < rhs)
	{
		mid = lhs + (rhs - lhs) / 2;
		if (nums[mid] <= target) lhs = mid;
		else rhs = mid - 1;
	}
	if (nums[rhs] == target) return rhs;
	else if (nums[lhs] == target) return lhs;
	else return -1; 
}

vector<int> searchRange_doubleBinSearch(vector<int>& nums, int target)
{
	int n = nums.size();
	int lhs = serachFirstOccurance(nums, target, 0, n - 1);
	if (lhs == -1) return{ -1, -1 };
	int rhs = serachLastOccurance(nums, target, 0, n - 1);
	return{ lhs, rhs };
}

/*
int main(int argc, char ** argv)
{
	//int input[] = { 5, 7, 7, 8, 8, 9 };
	//int input[] = { 8 };
	//int input[] = { 1 };
	int input[] = {1, 8};
	vector<int> nums(input, input + sizeof(input) / sizeof(int));

	vector<int> result;
	result = searchRange_doubleBinSearch(nums, 8);
	cout << "Result is " << result[0] <<"  "<< result[1] << endl;

	system("pause");
}
*/
