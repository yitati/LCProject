/*
 * SortColor.cpp
 *
一个disk有很多chunks，但只有三种类型称为A，B，C。要求把乱序的disk chunks重排为[A A A B B B B C C]，
所有A在前面，C在后面，B在中间，只能
  1) read某个index的chunk
  2) swap两个chunk的data 这两个操作来实现。
  follow up是尽量减少2）的次数

lc sort color, but要求swap次数最少。那个经典的法国国旗算法不work，不能保证swap最少，最优解是o(n)时间o(1)space，
  我没给出最优解，给出了o(n)时间o(n)space的。
 */

#include <vector>

using namespace std;

void sortChunks(vector<int>& nums)
{
	int n = nums.size();
	int startIdx[3] = {0, 0, 0};

	// count the number of chunk in one loop
	for(int num : nums) startIdx[num]++;

	// get the start index for each chunk
	startIdx[2] = startIdx[0] + startIdx[1];
	startIdx[1] = startIdx[0];
	startIdx[0] = 0;

	// move all 0 to the left side to [0 : startIdx[1]-1]
	int j = startIdx[0];
	for(int i=startIdx[1]; i<n; i++)
	{
		if(nums[i] == 0)
		{
			while(j < startIdx[1] && nums[j] == 0) j++;
			swap(nums[i], nums[j]);
		}
	}

	// move all 2 to the right side to [startIdx[2] : n-1]
	j = startIdx[2];
	for(int i=0; i<startIdx[2]; i++)
	{
		if(nums[i] == 2)
		{
			while(j < n && nums[j] == 2) j++;
			swap(nums[i], nums[j]);
		}
	}

}

/*
 * the 3 way partion is not least swap
 * [0, i) - 0
 * [i, k) - 1
 * [k, j] - unknown
 * (j, n-1) - 2
 */
void sortColors(vector<int>& nums)
{
	int n = nums.size();
	int i = 0, j = n - 1, k = 0;
	while (k <= j)
	{
		if (nums[k] == 0)
		{
			swap(nums[k++], nums[i++]);
		}
		else if (nums[k] == 2)
		{
			swap(nums[k], nums[j--]);
		}
		else
		{
			k++;
		}
	}
}


