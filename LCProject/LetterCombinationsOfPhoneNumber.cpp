/******************************************************************************
* Question: #17 Letter Combinations Of a Phone Number
* company tag: Amazon, Facebook
* Given a digit string, return all possible letter combinations that the number could represent.
* A mapping of digit to letters (just like on the telephone buttons) is given below.
Input:Digit string "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
Note:
Although the above answer is in lexicographical order, your answer could be in any order you want.
*****************************************************************************/

#include <string>
#include <vector>
#include <iostream>

using namespace std;

// dfs solution

const string dict[10] = { "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };

void letterMobile_dfs(string & digits, int idx, string & result, vector<string> & results)
{
	if (idx >= digits.size())
	{
		results.push_back(result);
		return;
	}
	int k = digits[idx]-'0';
	string curr = dict[k];
	for (int i = 0; i < curr.length(); i++)
	{
		result.push_back(curr[i]);
		letterMobile_dfs(digits, idx + 1, result, results);
		result.pop_back();
	}
}

vector<string> letterCombinations(string digits) 
{
	vector<string> results;
	if (digits.empty()) return results;
	string result;
	letterMobile_dfs(digits, 0, result, results);
	return results;
}

/*
int main(int argc, char ** argv)
{
	string input = "3456";
	vector<string> results = letterCombinations(input);
	for (int i = 0; i < results.size(); i++)
	{
		cout << results[i] << endl;
	}

	system("pause");
}
*/

