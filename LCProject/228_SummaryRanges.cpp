/******************************************************************************/
/*
* Question: #228 Summary Ranges
* Given a sorted integer array without duplicates, return the summary of its ranges.
For example, given [0,1,2,4,5,7], return ["0->2","4->5","7"].
*/
/*****************************************************************************/

#include <vector>
#include <string>

using namespace std;

vector<string> summaryRanges(vector<int>& nums) 
{
	vector<string> results;
	for (int i = 0; i < nums.size();)
	{
		string result;
		int start = i, end = i;
		result += to_string(nums[start]);
		while (end < nums.size() - 1 && nums[end + 1] == nums[end] + 1) end++;
		if (start < end)
		{
			result += "->";
			result += to_string(nums[end]);
		}
		results.push_back(result);
		i = end + 1;
	}
	return results;
}