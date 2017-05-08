/******************************************************************************/
/*
* Question: #398 Random Pick Index
* Given an array of integers with possible duplicates, randomly output the index of a given target number. 
* You can assume that the given target number must exist in the array. 

* Note:
* The array size can be very large. Solution that uses too much extra space will not pass the judge. 

Example: 
int[] nums = new int[] {1,2,3,3,3};
Solution solution = new Solution(nums);

// pick(3) should return either index 2, 3, or 4 randomly. Each index should have equal probability of returning.
solution.pick(3);

// pick(1) should return 0. Since in the array only nums[0] is equal to 1.
solution.pick(1);

*/
/*****************************************************************************/

#include <vector>

using namespace std;

// first idea was to use unordered_map to store all the value and indexes - but memory litmit exceeded.
// so read about reservior sampling https://en.wikipedia.org/wiki/Reservoir_sampling

int pick(int target, vector<int> array)
{
	// if we first find out the total number of elemts
	int count = 0, res = -1;
	for (int i = 0; i<array.size(); i++)
	{
		if (array[i] != target) continue;
		// need to increase count
		count++;
		if (count == 1) res = i; // this is to garentee that we can return i when there is only one
		else
		{
			// only change res when it hits the possibility
			if (!(rand() % count)) res = i;
		}
	}
	return res;
}