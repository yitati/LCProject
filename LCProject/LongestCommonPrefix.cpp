/******************************************************************************/
/*
* Question: #14 Longest Common Prefix
* Write a function to find the longest common prefix string amongst an array of strings.
*/
/*****************************************************************************/

#include <string>
#include <vector>

using namespace std;

string longestCommonPrefix(vector<string>& strs) 
{
    if(strs.empty()) return "";
    string prefix = strs[0];
    for(int i=1; i<strs.size(); i++)
    {
        int j = 0;
        while(j < strs[i].length() && j < prefix.length() && strs[i][j] == prefix[j]) j++;
        if(j == 0) return "";
        else
        {
            prefix = prefix.substr(0, j);
        }
    }
    return prefix;
}
