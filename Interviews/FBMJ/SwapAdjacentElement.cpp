/*
 * SwapAdjacentElement.cpp
 *
Given a string on length N. You can swap only the adjacent elements and each element can be swapped at most once.
Find the # of permutations of the string that can be generated after performing the swaps as mentioned.

Example:
string  -  "12345"
Ans: all permutations are
12345
21345
13245
12435
12354
21435
13254
21354
 */

#include <string>

using namespace std;

int count(string str)
{
	int len = str.length();
	vector<int> dp(len+1, 0);
	dp[0] = 0;
	dp[1] = 1;
	dp[2] = 2;
	for(int i=3; i<=len; i++)
	{
		dp[i] = dp[i-1] + dp[i-2];
	}
	return dp[len];
}



