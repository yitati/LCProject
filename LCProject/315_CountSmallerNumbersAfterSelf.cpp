/******************************************************************************/
/*
* Question: #315 Count of Smaller Numbers After Self
* You are given an integer array nums and you have to return a new counts array. 
* The counts array has the property where counts[i] is the number of smaller elements to the right of nums[i]. 

Example:
Given nums = [5, 2, 6, 1]

To the right of 5 there are 2 smaller elements (2 and 1).
To the right of 2 there is only 1 smaller element (1).
To the right of 6 there is 1 smaller element (1).
To the right of 1 there is 0 smaller element.

Return the array [2, 1, 1, 0]. 

*/
/*****************************************************************************/

// Solution - the merge sort idea - the smaller numbers on the right of a number are exactly those that jump from its 
// right to its left during a stable sort. 
// !!!!!!! Merge sort is stable sort !!!!!!!!!!!
// that means the relative position will not change if their orders are correct.
// but when doing merge sort we will change indices of the numbers, also we need couter to calculate the 
// count of smaller numbers after self for each number, so it is necessary to create a struct to store
// value, count, and original index

#include <vector>

using namespace std;

struct triplet;
vector<triplet> merge(vector<triplet>& lhs, vector<triplet>& rhs);
vector<triplet> merge(vector<triplet>& lhs, vector<triplet>& rhs);

vector<int> countSmaller(vector<int>& nums)
{
	vector<triplet> collect;
	vector<int> result(nums.size());
	for (int i = 0; i < nums.size(); i++)
	{
		collect.push_back(triplet(nums[i], 0, i));
	}

	collect = mergeSort(collect, 0, collect.size() - 1);
	// parse the result 
	for (int i = 0; i < nums.size(); i++)
	{
		result[collect[i].index] = collect[i].count;
	}
	return result;
}

struct triplet
{
	triplet(int v, int c, int i) : val(v), count(c), index(i) {};
	int val;      // value of this number
	int count;    // count of the smaller number in its right
	int index;	  // original index of the number 
};

// merge sort that will sort the tuple according to the value of number
vector<triplet> mergeSort(vector<triplet> nums, int lhs, int rhs)
{
	if (lhs > rhs) return{};
	vector<triplet> result;
	if (lhs == rhs)
	{
		result.push_back(nums[lhs]);
		return result;
	}
	int mid = lhs + (rhs - lhs) / 2;
	vector<triplet> left = mergeSort(nums, lhs, mid);
	vector<triplet> right = mergeSort(nums, mid + 1, rhs);
	return merge(left, right);
}
// in merge funtion, we need to handle merge and count the number of smaller 
// numbers that is switched to left
// when do right number shift to left ?  => when you take any element from rhs vector instead of lhs
// how do we count those numbers ? => we count them when we move lhs numbers, the count should be (j-0) 
// in which j is the pointer in the rhs
vector<triplet> merge(vector<triplet>& lhs, vector<triplet>& rhs)
{
	int i = 0, j = 0; // i is the pointer in lhs side and j is the pointer in rhs side
	vector<triplet> result;
	while (i < lhs.size() || j < rhs.size())
	{
		int opt1 = i == lhs.size() ? INT_MAX : lhs[i].val;
		int opt2 = j == rhs.size() ? INT_MAX : rhs[j].val;
		if (opt1 > opt2) // will get number from rhs (right number shift to left)
		{
			result.push_back(triplet(rhs[j].val, rhs[j].count, rhs[j].index));
			j++; // here is the counter
		}
		else // when moving lhs number, we sum up the counter
		{
			result.push_back(triplet(lhs[i].val, lhs[i].count + j, lhs[i].index));
			i++;
		}
	}
	return result;
}