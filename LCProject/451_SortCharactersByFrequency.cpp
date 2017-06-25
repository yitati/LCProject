/******************************************************************************/
/*
* Question: #451 Sort Characters By Frequency
* Given a string, sort it in decreasing order based on the frequency of characters.

Example 1: 
Input:
"tree"

Output:
"eert"

Explanation:
'e' appears twice while 'r' and 't' both appear once.
So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid answer.


Example 2: 
Input:
"cccaaa"

Output:
"cccaaa"

Explanation:
Both 'c' and 'a' appear three times, so "aaaccc" is also a valid answer.
Note that "cacaca" is incorrect, as the same characters must be together.



Example 3: 
Input:
"Aabb"

Output:
"bbAa"

Explanation:
"bbaA" is also a valid answer, but "Aabb" is incorrect.
Note that 'A' and 'a' are treated as two different characters.

*/
/*****************************************************************************/

#include <string>
#include <queue>
#include <unordered_map>

using namespace std;

class CharFreqComp
{
public:
	bool operator()(const pair<char, int> & lhs, const pair<char, int> & rhs) const
	{
		return (lhs.second < rhs.second);
	}
};

static CharFreqComp comp;

string frequencySort1(string s)
{
	priority_queue<pair<char, int>, vector<pair<char, int>>, CharFreqComp> maxHeap(comp);
	unordered_map<char, int> frequency;
	string result;
	for (int i = 0; i < s.length(); i++)
	{
		frequency[s[i]]++;
	}
	for (auto it : frequency)
	{
		maxHeap.push(it);
	}
	while (!maxHeap.empty())
	{
		pair<char, int> curr = maxHeap.top();
		maxHeap.pop();
		int freq = curr.second;
		int x = curr.first;
		result.append(freq, x);
	}
	return result;
}

// if we do not put pair<char, int> but put pair<int, char>, namely make frequency as the first element
// then no need to customize the sort funtion
// put frequency as the first element, then we do not need to customize the sort funtion
priority_queue<pair<int, char>> maxHeap;
// since we need to order the char by frequency, so heap can be used here
string frequencySort(string s)
{
	unordered_map<char, int> stat;
	// first we need to make stat for each of the char and its frequency
	for (char c : s) stat[c]++;
	// then push this char, int pair to max heap
	for (auto it = stat.begin(); it != stat.end(); it++)
	{
		maxHeap.push(make_pair(it->second, it->first));
	}

	string result;
	while (!maxHeap.empty())
	{
		auto it = maxHeap.top();
		maxHeap.pop();
		char c = it.second;
		int count = it.first;
		for (int i = 0; i<count; i++)
		{
			result.push_back(c);
		}
	}

	return result;
}
