/*
 * company tag: eBay
Given a string with no duplicate characters, return a list with all permutations of the characters.

Examples

Set = “abc”, all permutations are [“abc”, “acb”, “bac”, “bca”, “cab”, “cba”]
Set = "", all permutations are [""]
Set = null, all permutations are []
*/

#include <string>
#include <vector>

using namespace std;

void permute(vector<string> & results, string & input, int index)
{
	if (index == input.length())
	{
		results.push_back(input);
		return;
	}

	for (int i = index; i<input.size(); i++)
	{
		swap(input[i], input[index]);
		permute(results, input, index + 1);
		swap(input[i], input[index]);
	}
}

vector<string> solve(string input)
{
	vector<string> results;
	permute(results, input, 0);
	return results;
}

