/*
 * LetterCombinationPhoneNumber.cpp
 */

#include <string>
#include <vector>
#include <iostream>

using namespace std;

const string dict[10] = { "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };

void getLetterCombination(const string& digits, vector<string>& results, string& result, int pos)
{
	if(pos >= digits.size())
	{
		results.push_back(result);
		return;
	}

	int idx = digits[pos]-'0';
	string curr = dict[idx];
	for(char c : curr)
	{
		result.push_back(c);
		getLetterCombination(digits, results, result, pos+1);
		result.pop_back();
	}
}

vector<string> letterCombinations(string digits)
{
	vector<string> results;
	if(digits.empty()) return results;
	string result;
	getLetterCombination(digits, results, result, 0);
	return results;
}

/*
LC拾漆，有点区别是小哥并没有说是电话九宫格，
而是给一个List of List of letter，所以就不用考虑0这样的无效输入，一样的解法。
 */

