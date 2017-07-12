/**************************************************************************************************************************
 * Question #245. Shortest Word DistanceIII
 * company tag: LinkedIn
 * This is a follow up of Shortest Word Distance. The only difference is now word1 could be the same as word2.
 * Given a list of words and two words word1 and word2, return the shortest distance between these two words in the list.
 * word1 and word2 may be the same and they represent two individual words in the list.

For example,
Assume that words = ["practice", "makes", "perfect", "coding", "makes"].

Given word1 = “makes”, word2 = “coding”, return 1.
Given word1 = "makes", word2 = "makes", return 3.

 * Note:
 * You may assume word1 and word2 are both in the list.
 ************************************************************************************************************************/

#include <vector>
#include <string>
#include <climits>

using namespace std;

int shortestWordDistance(vector<string>& words, string word1, string word2)
{
	bool same = word1 == word2;
	long long diff = INT_MAX, i1 = -1, i2 = -1;
	for (int i = 0; i < words.size(); i++)
	{
		if (words[i] == word1)
		{
			i1 = i;
		}
		if (words[i] == word2)
		{
			if (same)
			{
				i1 = i2;  // update i1 to be last word to seen
			}
			i2 = i;
		}
		if (i1 != -1 && i2 != -1) diff = min(diff, abs(i2 - i1));
	}
	return diff;

}
