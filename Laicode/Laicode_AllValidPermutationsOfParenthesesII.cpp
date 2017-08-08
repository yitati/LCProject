/*
 * Laicode_AllValidPermutationsOfParenthesesII.cpp
 *
Get all valid permutations of l pairs of (), m pairs of [] and n pairs of {}.

Assumptions

l, m, n >= 0
Examples

l = 1, m = 1, n = 0, all the valid permutations are ["()[]", "([])", "[()]", "[]()"]

 */

#include <vector>
#include <string>
#include <stack>

using namespace std;

void fillPermutations(vector<string>& results, string& result, stack<char>& unmatched, vector<int>& count,
					vector<char>& left, vector<char>& right, vector<int>& limit)
{
	if(unmatched.empty() && count[0] == limit[0] && count[1]== limit[1] && count[2] == limit[2])
	{
		results.push_back(result);
		return;
	}

	// check for each parentheses
	for(int i=0; i<3; i++)
	{
		// condition to push left part
		if(count[i] < limit[i])
		{
			result.push_back(left[i]);
			count[i]++;
			unmatched.push(left[i]);
			fillPermutations(results, result, unmatched, count, left, right, limit);
			count[i]--;
			result.pop_back();
			unmatched.pop();
		}
		// condition to push right part
		if(!unmatched.empty() && unmatched.top() == left[i])
		{
			unmatched.pop();
			result.push_back(right[i]);
			fillPermutations(results, result, unmatched, count, left, right, limit);
			result.pop_back();
			unmatched.push(left[i]);
		}

	}
}

vector<string> solve(int l, int m, int n)
{
	vector<char> left = {'(', '[', '{'};
	vector<char> right = {')', ']', '}'};
	vector<int> count = {0, 0, 0}; // count for the left and right for three types
	vector<int> limit = {l, m, n};
	vector<string> results;
	string result = "";
	stack<char> unmatched;
	fillPermutations(results, result, unmatched, count, left, right, limit);
	return results;
}
