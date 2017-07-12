/*****************************************************************************************
 * Question #243 Shortest Word Distance
 * Given a list of words and two words word1 and word2, return the shortest distance between
 * these two words in the list.
 * company tag: LinkedIn

 For example,
 Assume that words = ["practice", "makes", "perfect", "coding", "makes"].

 Given word1 = “coding”, word2 = “practice”, return 3.
 Given word1 = "makes", word2 = "coding", return 1.

 * Note:
 * You may assume that word1 does not equal to word2, and word1 and word2 are both in the list.
 ****************************************************************************************/

#include <string>
#include <climits>

using namespace std;

int shortestDistance(vector<string>& words, string word1, string word2)
{
	int p1 = -1, p2 = -1, minDis = INT_MAX;
	for(int i=0; i<words.size(); i++)
	{
		if(words[i] == word1) p1 = i;
		if(words[i] == word2) p2 = i;
		if(p1 != -1 && p2 != -1)
		{
			minDis = abs(minDis, abs(p1-p2));
		}
	}
	return minDis;
}


