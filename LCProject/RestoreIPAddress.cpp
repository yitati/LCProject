/******************************************************************************/
/*
* Question: #93 Restore IP Address
* Given a string containing only digits, restore it by returning all possible valid IP address combinations.
For example:
Given "25525511135", 
* return ["255.255.11.135", "255.255.111.35"]. (Order does not matter) 
*/
/*****************************************************************************/

#include <vector>
#include <string>

using namespace std;

void restoreIpAddress_dfs(string & s, int section, int level, string result, vector<string> & results)
{
	if (section == 4)
	{
		if (level == s.length())
		{
			results.push_back(result);
		}
		return;
	}

	int num = 0;
	for (int i = 0; i < 3; i++)
	{
		num = num * 10 + s[level + i] - '0';
		if (s[level] == '0' && i>0) return;
		if (num >= 0 && num <= 255)
		{
			string curr = result;
			if (section != 0) curr += ".";
			curr = curr + to_string(num);
			restoreIpAddress_dfs(s, section + 1, level + i + 1, curr, results);
		}

	}
}
// each number from 0 to 255
vector<string> restoreIpAddresses(string s)
{
	vector<string> results;
	string result;
	restoreIpAddress_dfs(s, 0, 0, result, results);
	return results;
}