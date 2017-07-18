/******************************************************************************
* Question: #303 Range Sum Query - Immutable
* Given an integer array nums, find the sum of the elements between indices i and j (i ≤ j), inclusive.

Example:

Given nums = [-2, 0, 3, -5, 2, -1]

sumRange(0, 2) -> 1
sumRange(2, 5) -> -1
sumRange(0, 5) -> -3



* Note:
* 1.You may assume that the array does not change.
* 2.There are many calls to sumRange function.
*****************************************************************************/

#include <vector>
#include <unordered_map>

using namespace std;

class NumArray {
public:
	NumArray(vector<int> nums)
	{
		m_sumTable.resize(nums.size());
		int sum = 0;
		for (int i = 0; i < nums.size(); i++)
		{
			sum += nums[i];
			m_sumTable[i] = sum;
		}
	}

	int sumRange(int i, int j)
	{
		if (i == 0) return m_sumTable[j];
		return m_sumTable[j] - m_sumTable[i - 1];
	}

private:
	vector<int> m_sumTable;
};

/**
* Your NumArray object will be instantiated and called as such:
* NumArray obj = new NumArray(nums);
* int param_1 = obj.sumRange(i,j);
*/
