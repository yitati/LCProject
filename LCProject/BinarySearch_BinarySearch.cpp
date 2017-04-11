/*
Given an integer T and an integer array A sorted in ascending order, find the index i such that A[i] == T
or reutrn -1 if there is no such index.

Assumptions:
- There can be duplicate elements in the array, and you can return any of the indicates i such that A[i] == T.

Examples:
- A = {1, 2, 3, 4, 5}, T = 3, return 2
- A = {1, 2, 3, 4, 5}, T = 6, return -1
- A = {1, 2, 2, 2, 3, 4}, T = 2, return 1 or 2 or 3

Corner Cases:
- What if a is null or A is of zero length? We should return -1 in this case
*/


#include <vector>
#include <iostream>

using namespace std;

int binarySearch_basic(vector<int> & nums, int target)
{
	int n = nums.size();
	// if target out of bound, return -1
	if (target < nums[0] || target > nums[n - 1]) return -1;
	int lhs = 0, rhs = n - 1;
	while (lhs <= rhs) // when comming out of loop, lhs > rhs
	{
		int mid = lhs + (rhs - lhs) / 2;
		if (target == nums[mid]) return mid;
		else if (target < nums[mid]) rhs = mid - 1;
		else lhs = mid + 1;
	}
	return -1;
}

// another version
// if we want to have a range, say to find the number that is closet to the target,
// then we can use the following code snippet
int binarySearch_generic(vector<int> & nums, int target)
{
	int n = nums.size();
	// if target out of boundary, return -1
	if (target < nums[0] || target > nums[n - 1]) return -1;
	int lhs = 0, rhs = n - 1;
	while (lhs < rhs - 1) // when comming out of loop, at least 2 elements
	{
		int mid = lhs + (rhs - lhs) / 2;
		if (target == nums[mid]) return mid;
		else if (target < nums[mid]) lhs = mid;
		else rhs = mid;
	}
	// only lhs and rhs left, check the value
	if (nums[lhs] == target) return lhs;
	if (nums[rhs] == target) return rhs;
	return -1;
}

// advanced question 1 - first occurance
// if duplicates exist, find the first occurance of the target element
int binarySearch_firstOccurance(vector<int> & nums, int target)
{
	int n = nums.size();
	// if target out of boundary, return -1
	if (target < nums[0] || target > nums[n - 1]) return -1;
	int lhs = 0, rhs = n - 1;
	while (lhs < rhs - 1) // when comming out of loop, at least 2 elements
	{
		int mid = lhs + (rhs - lhs) / 2;
		if (target <= nums[mid]) rhs = mid;
		else lhs = mid+1;
	}
	// only lhs and rhs left, check the value
	if (nums[lhs] == target) return lhs;
	if (nums[rhs] == target) return rhs;
	return -1;
}


// advanced question 2 - last occurance
// if duplicates exist, find the last occurance of the target element
int binarySearch_lastOccurance(vector<int> & nums, int target)
{
	int n = nums.size();
	// if target out of boundary, return -1
	if (target < nums[0] || target > nums[n - 1]) return -1;
	int lhs = 0, rhs = n - 1;
	while (lhs < rhs - 1) // when comming out of loop, at least 2 elements
	{
		int mid = lhs + (rhs - lhs) / 2;
		if (target >= nums[mid]) lhs = mid;
		else rhs = mid-1;
	}
	// only lhs and rhs left, check the value
	if (nums[rhs] == target) return rhs;
	if (nums[lhs] == target) return lhs;
	return -1;
}


// advanced question 3 - closest in sorted array
// find the index i such that A[i] is closest to T
int binarySearch_closest(vector<int> & nums, int target)
{
	int n = nums.size();
	// if target out of boundary, return -1
	if (target <= nums[0] ) return 0;
	if (target >= nums[n - 1]) return n - 1;

	int lhs = 0, rhs = n - 1;
	while (lhs < rhs - 1) // when comming out of loop, at least 2 elements
	{
		int mid = lhs + (rhs - lhs) / 2;
		if (target == nums[mid]) return mid;
		else if (target < nums[mid]) rhs = mid;
		else lhs = mid;
	}
	// only lhs and rhs left, check the value
	int res1 = abs(nums[lhs] - target);
	int res2 = abs(nums[rhs] - target);
	return res1 <= res2 ? lhs : rhs;
}


// advanced question 4 - K closest in sorted array
// find the K closest numbers to T in A
vector<int> binarySearch_closest(vector<int> & nums, int target, int k)
{
	int n = nums.size();
	vector<int> result(k);
	int lhs = 0, rhs = n - 1;
	while (lhs < rhs - 1) // when comming out of loop, at least 2 elements
	{
		int mid = lhs + (rhs - lhs) / 2;
		if (target <= nums[mid]) rhs = mid;
		else lhs = mid;
	}
	// now we have lhs and rhs as the two boundaries for target
	// move whoever has smaller difference
	int i = 0; 
	while (i < k)
	{
		if (lhs < 0) 
		{
			result[i++] = nums[rhs++];
		}
		else if (rhs >= n)
		{
			result[i++] = nums[lhs--];
		}
		else if (abs(nums[lhs] - target) <= abs(nums[rhs] - target))
		{
			result[i++] = nums[lhs--];
		}
		else
		{
			result[i++] = nums[rhs++];
		}
	}

	return result;

}


/*
int main(int argc, char ** argv)
{
	int input[] = { 1,1,2,2,2,3,4,4,5,5,7,7,8,9 };
	vector<int> nums(input, input + sizeof(input) / sizeof(int));

	cout << "Test for binarySearch_basic() " << endl;
	cout << binarySearch_basic(nums, 2) << endl;    // expect 2
	cout << binarySearch_basic(nums, 6) << endl;    // expect -1
	cout << endl;

	cout << "Test for binarySearch_firstOccurance() " << endl;
	cout << binarySearch_firstOccurance(nums, 1) << endl;  // expect 0
	cout << binarySearch_firstOccurance(nums, 2) << endl;  // expect 2
	cout << binarySearch_firstOccurance(nums, 4) << endl;  // expect 6
	cout << binarySearch_firstOccurance(nums, 5) << endl;  // expect 8
	cout << binarySearch_firstOccurance(nums, 7) << endl;  // expect 10
	cout << endl;

	cout << "Test for binarySearch_lastOccurance() " << endl;
	cout << binarySearch_lastOccurance(nums, 1) << endl;  // expect 1
	cout << binarySearch_lastOccurance(nums, 2) << endl;  // expect 4
	cout << binarySearch_lastOccurance(nums, 4) << endl;  // expect 7
	cout << binarySearch_lastOccurance(nums, 5) << endl;  // expect 9
	cout << binarySearch_lastOccurance(nums, 7) << endl;  // expect 11
	cout << endl;

	cout << "Test for binarySearch_closest() " << endl;
	cout << binarySearch_closest(nums, 1) << endl;  
	cout << binarySearch_closest(nums, 6) << endl;  
	cout << endl;

	cout << "Test for K numbers closest to target" << endl;
	vector<int> close;
	close = binarySearch_closest(nums, 6, 5);
	int x = close.size();
	for (int i = 0; i < x; i++)
	{
		cout << close[i] << "   ";
	}
	cout<<endl;



	system("pause");
}
*/





