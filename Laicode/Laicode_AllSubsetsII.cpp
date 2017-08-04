/*
 * Laicode_AllSubsetsII.cpp
 *
Given a set of characters represented by a String, return a list containing all subsets of the characters.

Assumptions

There could be duplicate characters in the original set.
​Examples

Set = "abc", all the subsets are ["", "a", "ab", "abc", "ac", "b", "bc", "c"]
Set = "abb", all the subsets are ["", "a", "ab", "abb", "b", "bb"]
Set = "", all the subsets are [""]
Set = null, all the subsets are []

 */

#include <vector>
#include <string>
#include <algorithm>

using namespace std;

void fillSubsetsII(string& input, int pos, vector<string>& results, string path)
{
	results.push_back(path);
	if(pos >= input.size()) return;

	for(int i=pos; i<input.size(); i++)
	{
		if(i > pos && input[i] == input[i-1]) continue;
		path.push_back(input[i]);
		fillSubsetsII(input, i+1, results, path);
		path.pop_back();
	}
}

vector<string> allSubsetsII(string input)
{
	sort(input.begin(), input.end());
	vector<string> results;
	string path;
	fillSubsetsII(input, 0, results, path);
	return results;
}

