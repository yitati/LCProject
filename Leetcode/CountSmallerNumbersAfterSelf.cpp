/******************************************************************************
* Question: #315 Count of Smaller Numbers After Self
* company tag: eBay
* You are given an integer array nums and you have to return a new counts array. 
* The counts array has the property where counts[i] is the number of smaller elements to the right of nums[i]. 

Example:
Given nums = [5, 2, 6, 1]

To the right of 5 there are 2 smaller elements (2 and 1).
To the right of 2 there is only 1 smaller element (1).
To the right of 6 there is 1 smaller element (1).
To the right of 1 there is 0 smaller element.

Return the array [2, 1, 1, 0]. 

*****************************************************************************/

/*
 * Solution - the merge sort idea -
 * !!!!!! Merge Sort is Stable Sort !!!!!!!!!!!
 * That means the relative position will not change if their orders are correct.
 * So smaller number on the right of a number are exactly those that jump from its right to its
 * left during  stable sort.
 * But when doing merge sort we will change indices of the numbers, also we need counter to calculate
 * the count of smaller numbers after self for each number, so it is necessary to create a struct to
 * store value, count, and origianl index.
 */


#include <vector>
#include <climits>

using namespace std;

struct triplet
{
	triplet(int v, int c, int i) : val(v), count(c), index(i) {};
	int val;      // value of this number
	int count;    // count of the smaller number in its right
	int index;	  // original index of the number 
};

/*
 * in merge function, we need to handle merge and count the number of smaller numbers
 * that is switched to the left.
 * When do right number shift to left ? => When we take next number from rhs vector instead of lhs vector
 * How do we count those numbers ? => We count them when we move lhs numbers, the count should be (j-0) and
 * in which j is the pointer in rhs
 */
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
