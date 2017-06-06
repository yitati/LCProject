/*
Find all occurrence of anagrams of a given string s in a given string l. Return the list of starting indices.

Assumptions

s is not null or empty.
l is not null.
Examples

l = "abcbac", s = "ab", return [0, 3] since the substring with length 2 starting from index 0/3 are all anagrams of "ab" ("ab", "ba").
*/

#include <vector>
#include <string>
#include <unordered_map>
#include <iostream>

using namespace std;

vector<int> allAnagrams(string s, string l)
{
	if (s.empty() || l.empty()) return{};
	// create a differential table
	vector<int> results;
	unordered_map<char, int> table;
	for (char c : s) table[c]++;
	int lhs = 0, rhs = 0, minLen = 0, diff = table.size();

	while (rhs < l.length())
	{
		// add rhs in every loop
		if (table.count(l[rhs]))
		{
			table[l[rhs]]--;
			if (table[l[rhs]] == 0) diff--;
			else if (table[l[rhs]] == -1) diff++;
		}
		rhs++;
		// calc the len [lhs, rhs)
		while (rhs - lhs > s.length())
		{
			if (table.count(l[lhs]))
			{
				table[l[lhs]]++;
				if (table[l[lhs]] == 0) diff--;
				else if (table[l[lhs]] == 1) diff++;
			}
			lhs++;
		}
		// check index
		if (diff == 0) results.push_back(lhs);
	}
	return results;
}
/*
int main(int argc, char * argv[])
{
	//string s = "abcd";
	//string l = "abcdddiieejjfdcbakdkecdabkdkkeccdba";
	string s = "a";
	string l = "aaa";

	vector<int> results = allAnagrams(s, l);

	for (int i = 0; i < results.size(); i++)
	{
		cout << results[i] << "   ";
	}

	cout << endl;

	system("pause");
}
*/