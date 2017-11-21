/******************************************************************************
* Question: #127 Word Ladder
* company tag: Amazon, LinkedIn
* Given two words (beginWord and endWord), and a dictionary's word list, find the length of shortest transformation 
* sequence from beginWord to endWord, such that: 
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

* Return 0 if there is no such transformation sequence.
* All words have the same length.
* All words contain only lowercase alphabetic characters.
* You may assume no duplicates in the word list.
* You may assume beginWord and endWord are non-empty and are not the same.
*****************************************************************************/


#include <string>
#include <unordered_set>
#include <algorithm>
#include <climits>
#include <queue>

using namespace std;

// For the problem to get "min" distance we usually use bfs
int ladderLength_bfs(string beginWord, string endWord, vector<string>& wordList)
{
	// put all words into a set
	unordered_set<string> wordDict;
	for (string word : wordList) wordDict.insert(word);
	bool findResult = false;
	queue<string> words;
	words.push(beginWord);
	int step = 1;
	while (!words.empty())
	{
		if (findResult) break;
		if (wordDict.empty()) break;

		queue<string> next;
		step++;

		while (!words.empty())
		{
			string curr = words.front();
			words.pop();
			for (int i = 0; i<curr.length(); i++)
			{
				char ori = curr[i];
				for (char c = 'a'; c <= 'z'; c++)
				{
					curr[i] = c;
					// first check if this is the destination
					if (curr == endWord)
					{
						findResult = true;
						break;
					}
					if (wordDict.count(curr))
					{
						next.push(curr);
						wordDict.erase(curr);
					}
				}
				curr[i] = ori;
			}
		}
		words = next;
	}
	return findResult ? step : 0;
}

// a faster way is to use 2-way bfs, start bfs from both start point and destination
int ladderLength(string beginWord, string endWord, vector<string>& wordList)
{
	// put all the words into dictionary
	unordered_set<string> wordDict;
	for (string word : wordList)
	{
		wordDict.insert(word);
	}

	if (wordDict.count(endWord) == 0) return 0; //Corner case 1

	int step = 2;

	unordered_set<string> forward;
	unordered_set<string> backward;

	forward.insert(beginWord);
	backward.insert(endWord);

	wordDict.erase(beginWord);
	wordDict.erase(endWord);

	// use pointers here so we do not to re-code
	unordered_set<string> * marching;
	unordered_set<string> * reference;

	while (!forward.empty() && !backward.empty())
	{
		// because of concurrency, we can not popping and inserting at the same time
		unordered_set<string> next;

		if (forward.size() <= backward.size()) // loop the smaller set
		{
			marching = &forward;
			reference = &backward;
		}
		else
		{
			marching = &backward;
			reference = &forward;
		}

		for (auto it = marching->begin(); it != marching->end(); it++)
		{
			string curr = *it;

			for (int i = 0; i < curr.length(); i++)
			{
				char ori = curr[i];
				for (char c = 'a'; c <= 'z'; c++)
				{
					curr[i] = c;
					if (reference->count(curr))
					{
						return step;
					}
					if (wordDict.count(curr))
					{
						next.insert(curr);
						wordDict.erase(curr);  // we need to do the dedup here
					}
				}
				curr[i] = ori;
			}
		}
		*marching = next;
		step++;
	}
	return 0;
}

// Use dfs TLE
void buildLadder_dfs(string & startWord, string & endWord, unordered_set<string> & wordDict, int & steps, int & minSteps)
{
	if (startWord == endWord)
	{
		minSteps = min(minSteps, steps);
		return;
	}
	if (wordDict.empty()) return;

	for (int i = 0; i<startWord.length(); i++)
	{
		for (char c = 'a'; c <= 'z'; c++)
		{
			char ori = startWord[i];
			startWord[i] = c;
			if (wordDict.count(startWord))
			{
				steps++;
				wordDict.erase(startWord);
				buildLadder_dfs(startWord, endWord, wordDict, steps, minSteps);
				wordDict.insert(startWord);
				steps--;
			}
			startWord[i] = ori;
		}
	}
}

int ladderLength_dfs(string beginWord, string endWord, vector<string>& wordList)
{
	unordered_set<string> wordDict;
	int steps = 1, minSteps = INT_MAX;
	for (string word : wordList) wordDict.insert(word);
	buildLadder_dfs(beginWord, endWord, wordDict, steps, minSteps);
	if (minSteps == INT_MAX) return 0;
	else return minSteps;
}
