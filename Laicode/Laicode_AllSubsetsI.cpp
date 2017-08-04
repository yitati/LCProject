/*
 * Laicode_AllSubsetsI.cpp

Given a set of characters represented by a String, return a list containing all subsets of the characters.

Assumptions

There are no duplicate characters in the original set.
​Examples

Set = "abc", all the subsets are [“”, “a”, “ab”, “abc”, “ac”, “b”, “bc”, “c”]
Set = "", all the subsets are [""]
Set = null, all the subsets are []

 */

#include <vector>
#include <string>
#include <algorithm>

using namespace std;

void fillSubsetsI(string& input, int pos, vector<string>& results, string path)
{
	results.push_back(path);
	if(pos >= input.size()) return;

	for(int i=pos; i<input.size(); i++)
	{
		path.push_back(input[i]);
		fillSubsetsI(input, i+1, results, path);
		path.pop_back();
	}
}

vector<string> allSubsetsI(string input)
{
	sort(input.begin(), input.end());
	vector<string> results;
	string path;
	fillSubsetsI(input, 0, results, path);
	return results;
}


