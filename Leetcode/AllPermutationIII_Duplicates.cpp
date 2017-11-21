/*
 * company tag: eBay
Given a string with possible duplicate characters, return a list with all permutations of the characters.

Examples

Set = “abc”, all permutations are[“abc”, “acb”, “bac”, “bca”, “cab”, “cba”]
Set = "aba", all permutations are["aab", "aba", "baa"]
Set = "", all permutations are[""]
Set = null, all permutations are[]
*/


#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

void permuteduplicate(vector<string> & results, string & input, int index)
{
	if (index == input.size())
	{
		results.push_back(input);
		return;
	}
	// Use a hash set to store the char that already appreaed
	unordered_set<char> visit;

	for (int i = index; i<input.size(); i++)
	{
		if (visit.count(input[i])) continue;
		visit.insert(input[i]);
		swap(input[i], input[index]);
		permuteduplicate(results, input, index + 1);
		swap(input[i], input[index]);
	}
}

vector<string> permuteWithDupliates(string input)
{
	vector<string> results;
	permuteduplicate(results, input, 0);
	return results;
}
