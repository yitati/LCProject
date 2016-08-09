/******************************************************************************/
/**
* Question: #198 House Robber
* You ar a professional robber planning to rob houses along a street. Each house has
* a certain amount of money stashed, the only constraint stopping you from robbing
* each of them is that adjacent houses have security system connected and it will
* automatically contact the police if two adjacent houses were broken into on the
* same night.
* Given a list of non-negative integers representing the amount of money of each house,
* determine the maximum amount of money you can rob tonight without alerting the police.
*
*****************************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class HouseRob {
public:
	int rob1(vector<int>& nums)
	{
		int i;
		int n = nums.size();
		if (n == 0) return 0;
		vector<int>dp(n + 1, 0);
		dp[1] = nums[0];
		for (i = 2; i<n+1; i++)
		{
			dp[i] = std::max(dp[i - 1], dp[i - 2] + nums[i-1]);
		}
		return dp[n];
	}

	int rob2(vector<int>& nums)
	{
		int i;
		int a = 0, b = 0;
		int n = nums.size();
		if (n == 0) return 0;
		for (i = 0; i<n; i++)
		{
			if (i % 2 == 0)
			{
				a = max(a + nums[i], b);
			}
			else
			{
				b = max(b + nums[i], a);
			}
		}
		return max(a, b);
	}
};

/*
int main(int argc, char * argv)
{
	HouseRob rob;
	vector<int> nums = { 1, 1 };
	cout << rob.rob1(nums) << endl;
	cout << rob.rob2(nums) << endl;
	system("pause");
}
*/
