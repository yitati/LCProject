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

// Classical Version
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

// search one target inside sorted matrix
// sorted in each row and first element of each row is larger than last element in last row
bool ifFind(vector<vector<int>> & matrix, int target)
{
	if (matrix.empty() || matrix[0].empty()) return false;
	int row = matrix.size(), col = matrix[0].size();
	int lhs = 0, rhs = row*col - 1;
	while (lhs <= rhs)
	{
		int mid = lhs + (rhs - lhs) / 2;
		int r = mid / col, c = mid%col;
		if (matrix[r][c] == target) return true;
		else if (matrix[r][c] < target) lhs = mid + 1;
		else rhs = mid - 1;
	}
	return false;
}

// how to find an element in the array that is closest to the target number?
// we need to get 2 boundries and check which one is closest
int BinarySearchClosest(vector<int>& nums, int lhs, int rhs, int target)
{
	int mid;
	while (lhs < rhs - 1) // if left neighbors right -> terminate
	{
		mid = lhs + (rhs - lhs) / 2;
		if (nums[mid] == target) return mid;
		else if (nums[mid] < target) lhs = mid;
		else rhs = mid;
	}
	// post possessing
	if (abs(nums[lhs] - target) <= abs(nums[rhs] - target)) return lhs;
	else return rhs;
}

// find first occurrence of one target
int binarySearch_firstOccurrence(vector<int> & nums, int lhs, int rhs, int target)
{
	int mid;
	while (lhs < rhs - 1)  // if lhs neighbors rhs -> terminate
	{
		mid = lhs + (rhs - lhs) / 2;
		if (nums[mid] == target) rhs = mid;
		else if(nums[mid] > target) rhs = mid;
		// above two can be combined if(nums[mid] >= target) rhs = mid;
		else lhs = mid;
	}
	// post-processing first check lhs
	if (nums[lhs] == target) return lhs;
	else if (nums[rhs] == target) return rhs;
	return -1; // does not find target
}


// find last occurrence of one target
int binarySearch_lastOccurrence(vector<int> & nums, int lhs, int rhs, int target)
{
	int mid;
	while (lhs < rhs - 1)  // if lhs neighbors rhs -> terminate
	{
		mid = lhs + (rhs - lhs) / 2;
		if (nums[mid] == target) lhs = mid;
		else if (nums[mid] < target) lhs = mid;
		// above two can be combined if(nums[mid] <= target) rhs = mid;
		else rhs = mid;
	}
	// post-processing first check rhs
	if (nums[rhs] == target) return lhs;
	else if (nums[lhs] == target) return rhs;
	return -1; // does not find target
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





