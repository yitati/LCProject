/******************************************************************************/
/*
* Question: #425 Word Squares
Given a set of words (without duplicates), find all word squares you can build from them.

A sequence of words forms a valid word square if the kth row and column read the exact same string, 
where 0 ≤ k < max(numRows, numColumns).

For example, the word sequence ["ball","area","lead","lady"] forms a word square because each word 
reads the same both horizontally and vertically.

b a l l
a r e a
l e a d
l a d y
Note:
There are at least 1 and at most 1000 words.
All words will have the exact same length.
Word length is at least 1 and at most 5.
Each word contains only lowercase English alphabet a-z.
Example 1:

Input:
["area","lead","wall","lady","ball"]

Output:
[
[ "wall",
"area",
"lead",
"lady"
],
[ "ball",
"area",
"lead",
"lady"
]
]

Explanation:
The output consists of two word squares. The order of output does not matter (just the order of 
words in each word square matters).
Example 2:

Input:
["abat","baba","atan","atal"]

Output:
[
[ "baba",
"abat",
"baba",
"atan"
],
[ "baba",
"abat",
"baba",
"atal"
]
]

Explanation:
The output consists of two word squares. The order of output does not matter (just the order 
of words in each word square matters).
*/
/*****************************************************************************/

#include <unordered_map>
#include <vector>
#include <string>

using namespace std;

class WordSquares
{
public:
	vector<vector<string>> wordSquares(vector<string>& words)
	{
		for (string word : words) dict.insert(word);
		vector<vector<string>> results;
		for (string word : words)
		{
			vector<string> square;
			square.push_back(word);
			findAllWordSquare(results, square, word, 1);
		}
		return results;
	}
private:
	void findAllWordSquare(vector<vector<string>> & results, vector<string> & square, string & last, int level)
	{
		// termination condition
		if (level == last.length())
		{
			results.push_back(square);
			return;
		}
		// calculate the prefix
		string prefix;
		for (int i = 0; i < level; i++)
		{
			prefix.push_back(square[i][level]);
		}
		vector<string> collections;
		dict.allPrefix(prefix, collections);
		for (int i = 0; i < collections.size(); i++)
		{
			square.push_back(collections[i]);
			findAllWordSquare(results, square, collections[i], level + 1);
			square.pop_back();
		}
	}

	// first we need a trie node class
	class TrieNode
	{
	public:
		TrieNode()
		{
			isWord = false;
		}
		bool isWord;
		unordered_map<char, TrieNode *> children;
	};
	// then construct the trie class
	class Trie // same as trie but different name here
	{
	public:
		Trie()
		{
			root = new TrieNode();
		}

		void insert(const string & word)
		{
			if (word.empty()) return;
			TrieNode * node = root;
			for (char c : word)
			{
				if (!node->children.count(c))
				{
					node->children[c] = new TrieNode();
				}
				node = node->children[c];
			}
			node->isWord = true;
		}

		TrieNode * search(const string & word)
		{
			if (word.empty()) return NULL;
			TrieNode * node = root;
			for (char c : word)
			{
				if (!node->children.count(c)) return NULL;
				node = node->children[c];
			}
			return node;
		}

		// function that will find all words with given prefix
		void allPrefix(string & prefix, vector<string> & collections)
		{
			if (prefix.empty()) return;

			TrieNode * node = search(prefix);
			if (!node) return;
			string result = prefix;
			fillAllPrefix(node, prefix, collections);

		}
		// function that will fill all prefix from one point
		void fillAllPrefix(TrieNode * node, string & result, vector<string> & collections)
		{
			if (!node) return;
			if (node->isWord)
			{
				collections.push_back(result);
			}
			for (auto it = node->children.begin(); it != node->children.end(); it++)
			{
				result.push_back(it->first);
				fillAllPrefix(it->second, result, collections);
				result.pop_back();
			}
		}



	private:
		TrieNode * root;
	};

	// word square private member tire dict
	Trie dict;
};
