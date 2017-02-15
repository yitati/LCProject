/******************************************************************************/
/*
* Question: #22 Generate Parentheses
* Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

For example, given n = 3, a solution set is:

[
  "((()))",
  "(()())",
  "(())()",
  "()(())",
  "()()()"
]
*/
/*****************************************************************************/

#include <string>
#include <vector>
#include <iostream>

using namespace std;

// use dfs solution

void generateParenthesis_dfs(vector<string> & results, string & result, int n, int leftCount, int rightCount)
{
	if (result.size() == 2 * n)
	{
		results.push_back(result);
		return;
	}

	// if we can only push back '0'
	if (leftCount < n)
	{
		result.push_back('(');
		generateParenthesis_dfs(results, result, n, leftCount+1, rightCount);
		result.pop_back();
	}
	if (leftCount > rightCount)
	{
		result.push_back(')');
		generateParenthesis_dfs(results, result, n, leftCount, rightCount+1);
		result.pop_back();
	}
	
}

vector<string> generateParenthesis(int n) 
{
	vector<string> results;
	if(n == 0) return results;
	string result;
	generateParenthesis_dfs(results, result, n, 0, 0);
	return results;
}

/*
int main(int argc, char ** argv)
{
	vector<string> results = generateParenthesis(3);
	for (int i = 0; i < results.size(); i++)
	{
		cout << results[i] << endl;
	}
	system("pause");
}
*/