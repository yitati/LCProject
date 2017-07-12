/***********************************************************************************
 * Question #254 Factor Combination
 * Numbers can be regarded as product of its factors. For example,
 8 = 2 x 2 x 2;
   = 2 x 4.

 * Write a function that takes an integer n and return all possible combinations of its factors.
 * Note:
 * 1.You may assume that n is always positive.
 * 2.Factors should be greater than 1 and less than n.
 *
Examples:
 input: 1
 output:

[]

input: 37
 output:
[]

input: 12
 output:
[
  [2, 6],
  [2, 2, 3],
  [3, 4]
]

input: 32
 output:
[
  [2, 16],
  [2, 2, 8],
  [2, 2, 2, 4],
  [2, 2, 2, 2, 2],
  [2, 4, 4],
  [4, 8]
]
 *
 ***********************************************************************************/

#include <vector>

using namespace std;

// the minimal factor is 2
void findFactors(vector<vector<int>>& results, vector<int>& result, int currFactor, int target)
{
	for(int i=currFactor; i*i <= target; i++)
	{
		if(target%i != 0) continue;
		vector<int> subres = result;
		subres.push_back(i);
		findFactors(results, subres, i, target/i);
		subres.push_back(target/i);
		results.push_back(subres);
	}
}

vector<vector<int>> getFactors(int n)
{
	vector<vector<int>> results;
	vector<int> result;
	findFactors(results, result, 2, n);
	return results;
}



