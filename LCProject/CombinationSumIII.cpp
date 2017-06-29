/******************************************************************************/
/*
* Question: #216 Combination Sum III
* Find all possible combinations of k numbers that add up to a number n, 
* given that only numbers from 1 to 9 can be used and each combination should be a unique set of numbers.

Example 1:

Input: k = 3, n = 7

Output:

[[1,2,4]]

Example 2:

Input: k = 3, n = 9

Output:

[[1,2,6], [1,3,5], [2,3,4]]
*/
/*****************************************************************************/


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void combSum_dfs3(vector<vector<int>> & results, vector<int> & result, int k, int target)
{
	if (result.size() == k && target == 0)
	{
		results.push_back(result);
		return;
	}
	int i = result.empty() ? 1 : result.back() + 1;
	for (; i < 10; i++)
	{
		result.push_back(i);
		combSum_dfs3(results, result, k, target - i);
		result.pop_back();
	}
}

vector<vector<int>> combinationSum3(int k, int n)
{
	vector<vector<int>> results;
	vector<int> result;
	combSum_dfs3(results, result, k, n);
	return results;
}