/**********************************************************
 * Question #291 Word Pattern II
 *
 * Given a pattern and a string str, find if str follows the same pattern.
 * Here follow means a full match, such that there is a bijection between a letter in
 * pattern and a non-empty substring in str.
 *
 * Examples:
 * 1.pattern = "abab", str = "redblueredblue" should return true.
 * 2.pattern = "aaaa", str = "asdasdasdasd" should return true.
 * 3.pattern = "aabb", str = "xyzabcxzyabc" should return false.
 * Notes:
 * You may assume both pattern and str contains only lowercase letters.
 *
 **********************************************************/

#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <iostream>

using namespace std;

// i is the pos to check in pattern and j is pos to check in str
// if we are looking for signle direction project, we don't need set
// but there is one corner that is two char match to same string : pattern = "ab" str = "ab"
// we need to use visited set to eliminate this corner case
 bool findMatch(string& pat, unsigned int i, string& str, unsigned int j,
		 unordered_map<char, string>& history, unordered_set<string>& visited)
 {
     // termination condition
     if(i == pat.length() && j == str.length()) return true;
     if(i == pat.length() || j == str.length()) return false;
     // what we do in this layer
     char curr = pat[i];
     if(history.count(curr))
     {
    	 // here we need to check the whole string
    	 string match = history[curr];
    	 int matchLen = match.length();
    	 string check = str.substr(j, matchLen);
    	 if(match != check) return false;
         else
         {
             return findMatch(pat, i+1, str, j + history[curr].length(), history, visited);
         }
     }
     else // new string
     {
         for(int len = 1; j + len <= str.length(); len++)
         {
        	 string cand = str.substr(j, len);
        	 if(visited.count(cand)) continue;
        	 history[curr] = cand;    // mem DFS
        	 visited.insert(cand);    // check for double projection
        	 if(findMatch(pat, i+1, str, j+len, history, visited)) return true;
        	 history.erase(curr);     // back tracking
        	 visited.erase(cand);     // back tracking
         }
     }
     return false;
 }

 bool wordPatternMatch(string pattern, string str)
 {
 	unordered_map<char, string> history;
 	unordered_set<string> visited;
 	return findMatch(pattern, 0, str, 0, history, visited);
 }

 /*
 int main(int argc, char ** argv)
 {
	 string pattern = "eecs";
	 string str = "electronicengineeringcomputerscience";  //should be false
	 cout << wordPatternMatch(pattern, str) << endl;
 }
 */




