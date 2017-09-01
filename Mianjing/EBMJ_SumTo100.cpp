/**
* Given a ordered set of integers from 1 to 9. Combine them using + or - or nothing,
* such that the resulting equation sum is 100.
* Ex: 1 + 2 + 34 - 5 + 67 - 8 + 9 = 100
* or 1 + 2 + 3 - 4 + 5 + 6 + 78 + 9
*/

#include <vector>
#include <string>

using namespace std;

// TODO - today

void fillEquations(vector<string>& results, const vector<int>& nums, int pos, int currVal, string currStr, int target)
{
	if(pos >= nums.size())
	{
		if(target == 0)
		{
			results.push_back(currStr);
		}
		return;
	}

	int nextVal = 0;
	for(int i=pos; i<nums.size(); i++)
	{
		nextVal = nextVal*10 + nums[i];
		if(currVal == 0)
		{
			fillEquations(results, nums, i+1, nextVal, to_string(nextVal), target-nextVal);
		}
		else
		{
			// add '+'
			fillEquations(results, nums, i+1, currVal + nextVal, currStr + "+" + to_string(nextVal), target-nextVal);
			// add '-'
			fillEquations(results, nums, i+1, currVal - nextVal, currStr + "-" + to_string(nextVal), target+nextVal);
		}
	}
}

// target == 100
vector<string> getAllEquations(int target)
{
	vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	vector<string> results;
	fillEquations(results, nums, 0, 0, "", target);
	return results;
}



