/**********************************************
* Question: #316 RemoveDuplicateLatters
* Given a string which contains only lowercase letters, remove duplicate letters so that every letter
* appear once and only once. You must make sure your result is the smallest in lexicographical
* order among all possible results.

Example:

Given "bcabc"
Return "abc"

Given "cbacdcbc"
Return "acdb"

************************************************/

#include <string>
#include <vector>

using namespace std;

// O(n) solution
string removeDuplicateLetters(string s)
{
	vector<int> freq(26, 0);
	vector<bool> visited(26, false);
	string result = "0";
	for(char c : s) freq[c-'a']++;
	for(char c : s)
	{
	    int idx = c-'a';
	    freq[idx]--;   // since c has been scanned so we remove one apperance from the string
	    if(visited[idx]) continue;
	    while(c < result.back() && freq[result.back()-'a'] > 0)  // if the last element is larger and can be replaced later
	    {
	        visited[result.back()-'a'] = false;
	        result.pop_back();
	    }
	    result.push_back(c);
	    visited[idx] = true;
	}
	return result.substr(1);
}






