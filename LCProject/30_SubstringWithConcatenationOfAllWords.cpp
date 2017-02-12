/******************************************************************************/
/*
* Question: #30 Substring With Concatenation of All Words
* You are given a string, s, and a list of words, words, that are all of the same length. 
* Find all starting indices of substring(s) in s that is a concatenation of each word in words exactly once and without any intervening characters.

For example, given:
s: "barfoothefoobarman"
words: ["foo", "bar"]

You should return the indices: [0,9].
(order does not matter).
*/
/*****************************************************************************/

#include <vector>
#include <unordered_map>

using namespace std;

vector<int> findSubstring(string S, vector<string> &L)
{
	vector<int> result;
	if (S.empty() || L.empty()) return result;
	int dictLen = L.size();
	int wl = L[0].size();

	// build a dictionary for the words
	unordered_map<string, int> dict;
	for (string word : L)
	{
		dict[word]++;
	}

	for (int i = 0; i < wl; i++)
	{
		int start = i, count = 0;
		unordered_map<string, int> tdict;
		for (int j = i; j + wl <= S.length(); j += wl)
		{
			string curr = S.substr(j, wl);
			// if this is an valid string
			if (dict.count(curr))
			{
				tdict[curr]++;
				if (tdict[curr] <= dict[curr]) count++;
				else
				{
					while (tdict[curr] > dict[curr])
					{
						if (start + wl >= S.length()) break;
						string prev = S.substr(start, wl);
						if (tdict[prev] <= dict[prev]) count--;
						tdict[prev]--;
						start += wl;
					}
				}

				// push result and forward one more word
				if (count == dictLen)
				{
					result.push_back(start);
					if (start + wl > S.length()) break;
					string first = S.substr(start, wl);
					tdict[first]--;
					count--;
					start += wl;
				}
			}
			else
			{
				tdict.clear();
				count = 0;
				start = j + wl;
			}
		}
	}

	return result;
}