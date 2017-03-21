/******************************************************************************/
/*
* Question: #77 Combinations
* Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.

For example,
If n = 4 and k = 2, a solution is:

[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]
*/
/*****************************************************************************/

#include <vector>
#include <iostream>
#include <string>

using namespace std;

void combine_recursion(vector<vector<int>> & results, vector<int> & result, int n, int level, int k)
{
	if (k == 0)
	{
		results.push_back(result);
		return;
	}

	for (int i = level; i < n + 1; i++)
	{
		result.push_back(i);
		combine_recursion(results, result, n, i + 1, k - 1);
		result.pop_back();
	}
}

vector<vector<int>> combine(int n, int k)
{
	vector<vector<int>> results;
	if (n == 0) return results;
	vector<int> result;
	combine_recursion(results, result, n, 1, k);
	return results;
}
