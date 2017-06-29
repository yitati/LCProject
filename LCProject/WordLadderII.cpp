/******************************************************************************/
/*
* Question: #126 Word Ladder II
* Given two words (beginWord and endWord), and a dictionary's word list, Given two words (beginWord and endWord), 
* and a dictionary's word list, find all shortest transformation sequence(s) from beginWord to endWord, such that: 
* 1.Only one letter can be changed at a time.
* 2.Each transformed word must exist in the word list. Note that beginWord is not a transformed word.

For example,

Given:
beginWord = "hit"
endWord = "cog"
wordList = ["hot","dot","dog","lot","log","cog"]


As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
return its length 5.

* Note:

* Return an empty list if there is no such transformation sequence.
* All words have the same length.
* All words contain only lowercase alphabetic characters.
* You may assume no duplicates in the word list.
* You may assume beginWord and endWord are non-empty and are not the same.
*/
/*****************************************************************************/

#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

vector<string> getPathStrings(string beginWord, vector<int> & result, vector<string> & wordList)
{
	vector<string> one;
	one.push_back(beginWord);
	for (int index : result)
	{
		one.push_back(wordList[index]);
	}
	return one;
}

vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList)
{
	vector<vector<string>> results;

	unordered_map<string, int> wordDict;
	for (int i = 0; i < wordList.size(); i++)
	{
		wordDict[wordList[i]] = i;
	}

	if (!wordDict.count(endWord)) return results;

	unordered_map<string, vector<vector<int>>> layer;
	layer[beginWord] = { {} };

	bool findResult = false;

	wordDict.erase(beginWord);
	wordDict.erase(endWord);

	while (!layer.empty())
	{
		if (findResult) break;
		// store the next layer
		unordered_map<string, vector<vector<int>>> next;
		unordered_set<string> visited;

		for (auto it = layer.begin(); it != layer.end(); it++)
		{
			string curr = it->first;
			for (int i = 0; i < curr.length(); i++)
			{
				char ori = curr[i];
				for (char c = 'a'; c <= 'z'; c++)
				{
					curr[i] = c;
					if (curr == endWord)
					{
						for (int k = 0; k < it->second.size(); k++)
						{
							vector<string> one = getPathStrings(beginWord, it->second[k], wordList);
							one.push_back(endWord);
							results.push_back(one);
						}

						findResult = true;
						break;
					}
					if (wordDict.count(curr))
					{
						for (int k = 0; k<it->second.size(); k++)
						{
							vector<int> item = it->second[k];
							item.push_back(wordDict[curr]);
							next[curr].push_back(item);
						}
						visited.insert(curr);
					}
				}
				curr[i] = ori;
			}
		}

		for (auto it = visited.begin(); it != visited.end(); it++)
		{
			wordDict.erase(*it);
		}

		layer = next;
	}
	return results;
}