/*
 * Laicode_KthSmallestWtihOnly23AsFactors.cpp
 *
Find the Kth smallest number s such that s = 2 ^ x * 3 ^ y, x >= 0 and y >= 0, x and y are all integers.

Assumptions

K >= 1
Examples

the smallest is 1
the 2nd smallest is 2
the 3rd smallest is 3
the 5th smallest is 2 * 3 = 6
the 6th smallest is 2 ^ 3 * 3 ^ 0 = 8

 */

#include <vector>

using namespace std;
/*
 * simplified version of super ugly number
 */
int kth(int k)
{
	// this is the index of generated numbers
	int index2 = 0, index3 = 0;
	vector<int> nums;
	nums.push_back(1);

	while(nums.size() < k)
	{
		int twoNum = nums[index2]*2;
		int threeNum = nums[index3]*3;
		if(twoNum <= threeNum)
		{
			if(nums.back() != twoNum)
			{
				nums.push_back(twoNum);
			}
			index2++;
		}
		else
		{
			if(nums.back() != threeNum)
			{
				nums.push_back(threeNum);
			}
			index3++;
		}
	}

	return nums.back();
}




