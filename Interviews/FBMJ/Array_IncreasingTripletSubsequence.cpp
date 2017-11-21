/******************************************************************************/
/*
* Question: #334 Increasing Triplet Subsequence
* Given an unsorted array return whether an increasing subsequence of length 3 exists or not in the array. 
* Formally the function should:
* Return true if there exists i, j, k  
* such that arr[i] < arr[j] < arr[k] given 0 ≤ i < j < k ≤ n-1 else return false. 

* Your algorithm should run in O(n) time complexity and O(1) space complexity. 

Examples:
 Given [1, 2, 3, 4, 5],
 return true. 

Given [5, 4, 3, 2, 1],
 return false. 

*/
/*****************************************************************************/

#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

/*
 * O(n) time solution, let's keep two candidate values cand1 and cand2 to cut the whole array into
 * three pieces
 * [-&, cand1]
 * (cand1, cand2]
 * (cand2, +&]
 * if we find number in those three pieces then find our results.
 * O(n) time
 */
bool increseTriplet(vector<int>& nums)
{
	int cand1 = INT_MAX, cand2 = INT_MAX;
	for(int num : nums)
	{
		if(num <= cand1) cand1 = num;           // try to make cand1 and cand2 as small as possible
		else if(num <= cand2) cand2 = num;
		else return true;
	}
	return false;
}

// refer to problem 300 - longest increasing subsequence O(nlogn) time
// now if we find any increasing sequence with length >= 3, will return true
bool increasingTriplet(vector<int>& nums)
{
	vector<int> incSequence;
	for (int num : nums)
	{
		auto it = lower_bound(incSequence.begin(), incSequence.end(), num);
		if (it == incSequence.end())
		{
			incSequence.push_back(num);
			if (incSequence.size() == 3) return true;
		}
		else
		{
			*it = num;
		}
	}
	return false;
}
