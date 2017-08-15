/******************************************************************************/
/*
* Question: #248 Strobogrammatic Number III
* company tag: Facebook, Google
* A strobogrammatic number is a number that looks the same when rotated 180 degrees (looked at upside down).
* Write a function to count the total strobogrammatic numbers that exist in the range of low <= num <= high.
* For example,
* Given low = "50", high = "100", return 3. Because 69, 88, and 96 are three strobogrammatic numbers.
* Note:
* Because the range might be a large number, the low and high numbers are represented as string.
*/
/*****************************************************************************/

#include <string>
#include <vector>

using namespace std;
/*
 *  a helper function that does string compare, returns true if s1 < s2
 */
bool compare(const string s1, const string s2)
{
	if(s1.length() != s2.length())
	{
		return s1.length() < s2.length();
	}

	for(int i=0; i<s1.length(); i++)
	{
		if(s1[i] < s2[i]) return true;
		else if(s1[i] > s2[i]) return false;
	}

	return true;  // when they equal
}

void fillStroboNumIII_dfs(vector<pair<string, string>>& nums, string low, string high, string result, int& count)
{
	if(result.length() > high.length())
	{
		return;
	}

	if(compare(low, result) && compare(result, high))
	{
		if(result.length() == 1 || (result.length() > 1 && result[0] != '0'))
		{
			count++;
		}
	}

	for(int i=0; i<nums.size(); i++)
	{
		fillStroboNumIII_dfs(nums, low, high, nums[i].first + result + nums[i].second, count);
	}
}


int strobogrammaticInRange(string low, string high)
{
	vector<pair<string, string>> nums = {{"0", "0"}, {"1", "1"}, {"8", "8"},  {"6", "9"},  {"9", "6"}};

	int count = 0;
	fillStroboNumIII_dfs(nums, low, high, "", count);
	fillStroboNumIII_dfs(nums, low, high, "0", count);
	fillStroboNumIII_dfs(nums, low, high, "1", count);
	fillStroboNumIII_dfs(nums, low, high, "8", count);

	return count;
}
