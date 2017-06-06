/******************************************************************************/
/*
* Question: #163 Missing Ranges
* Given a sorted integer array where the range of elements are in the inclusive range [lower, upper], 
* return its missing ranges.

For example, given [0, 1, 3, 50, 75], lower = 0 and upper = 99, return ["2", "4->49", "51->74", "76->99"].
*/
/*****************************************************************************/

#include <vector>
#include <string>

using namespace std;

vector<string> findMissingRanges(vector<int>& nums, int lower, int upper)
{
	vector<string> results;
	long long prev = (long)lower - 1, next = 0;
	for (int i = 0; i <= nums.size(); i++)
	{
		string result;
		next = i == nums.size() ? (long)upper + 1 : nums[i];
		if (prev + 2 == next)
		{
			result += to_string(prev + 1);
		}
		else if (prev + 2 < next)
		{
			result += to_string(prev + 1) + "->" + to_string(next - 1);
		}
		if (!result.empty()) results.push_back(result);
		prev = next;
	}
	return results;
}