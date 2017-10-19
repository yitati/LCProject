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
 * 题目：破解密码，提供了一个函数，isPassword(String str)，如果pass in的是正确的密码，return true。
 * 又给定了每个字母可以变形的集合（例如，字母a可以变形为a或者A或者B或者*, 字母b可以变形为B或者F或者&...，
 * 需要自己设计一个data structure来存这个mapping），设计并实现一个函数，在给定一个字符串的情况下，对字符串进行变形，最后找到正确的密码。
 * same with above solution, we need to first come up with the encoding table
 */

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

