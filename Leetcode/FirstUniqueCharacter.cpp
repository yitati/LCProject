/******************************************************************************
* Question: #387 First Unique Character in a String
* company tag: Amazon
* Given a string, find the first non-repeating character in it and return it's index. If it doesn't exist, return -1.

Examples:

s = "leetcode"
return 0.

s = "loveleetcode",
return 2.

* Note: You may assume the string contain only lowercase letters.
*****************************************************************************/

#include <string>
#include <unordered_map>
#include <set>

using namespace std;

// O(n) solution that uses one
int firstUniqChar(string s)
{
    unordered_map<char, int> table; // keep the number and the index
    set<int> index; // keep only the indices of unique numbers
    for(int i=0; i<s.length(); i++)
    {
        if(!table.count(s[i]))
        {
            index.insert(i);
            table[s[i]] = i;
        }
        else
        {
            int toremove = table[s[i]];
            index.erase(toremove);
        }
    }
    if(index.empty()) return -1;
    return *index.begin();
}


