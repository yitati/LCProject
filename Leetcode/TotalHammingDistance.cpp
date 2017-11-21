/******************************************************************************/
/*
* Question: #477 Total Hamming Distance
* The Hamming distance between two integers is the number of positions at which the corresponding bits are different.
* Now your job is to find the total Hamming distance between all pairs of the given numbers. 

Example:
Input: 4, 14, 2
Output: 6
Explanation: In binary representation, the 4 is 0100, 14 is 1110, and 2 is 0010 (just
showing the four bits relevant in this case). So the answer will be:
HammingDistance(4, 14) + HammingDistance(4, 2) + HammingDistance(14, 2) = 2 + 2 + 2 = 6.

* Note:
* 1.Elements of the given array are in the range of 0  to 10^9 
* 2.Length of the array will not exceed 10^4. 
*/
/*****************************************************************************/

#include <vector>

using namespace std;

int getHammingDistance(int x, int y)
{
	int diff = x^y;
	int count = 0;
	while (diff)
	{
		diff &= (diff - 1);
		count++;
	}
	return count;
}

// simple solution by calculating each pair - TLE
int totalHammingDistance1(vector<int>& nums) 
{
	if (nums.empty() || nums.size() < 2) return 0;
	int dis = 0;
	for (int i = 0; i < nums.size() - 1; i++)
	{
		for (int j = i + 1; j < nums.size(); j++)
		{
			dis += getHammingDistance(nums[i], nums[j]);
		}
	}
	return dis;
}

// improved solution - there are only 32 bit in on int
// for each bit calculate how many 1 (for example x) and how many 0 (for example y)
// then we got x*y hamming distance for this bit
// stat 32 bit then we got sum
int totalHammingDistance2(vector<int>& nums)
{
	if (nums.empty() || nums.size() < 2) return 0;
	int total = 0;
	for (int i = 0; i < 32; i++)
	{
		int count0 = 0, count1 = 0;
		for (int num : nums)
		{
			int mask = 1 << i;
			if ((num & mask) == mask) count1++;
			else count0++;
		}
		total += count0 * count1;
	}
	return total;
}