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

void restoreIpAddress_dfs(string & s, int section, int pos, string& result, vector<string> & results)
{
    if (section >= 4)
    {
        if (pos == s.length())
        {
            results.push_back(result);
        }
        return;
    }

    int num = 0;
    int orisize = result.size();
    if(section != 0) result.push_back('.');

    // there are maximum 3 digits
    for (int i = 0; i < 3; i++)
    {
        if (s[pos] == '0' && i > 0) break;
        num = num * 10 + s[pos + i] - '0';
        if (num >= 0 && num <= 255)
        {
            result.push_back(s[pos + i]);
            restoreIpAddress_dfs(s, section + 1, pos + i + 1, result, results);
        }
    }
    result.resize(orisize);
}
// each number from 0 to 255
vector<string> restoreIpAddresses(string s)
{
    vector<string> results;
    string result;
    restoreIpAddress_dfs(s, 0, 0, result, results);
    return results;
}
