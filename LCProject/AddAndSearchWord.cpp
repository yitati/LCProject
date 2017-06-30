/******************************************************************************/
/*
* Question: #211 Add and Search Word - Data structure design
* Design a data structure that supports the following two operations: 
* void addWord(word)
* bool search(word)

* search(word) can search a literal word or a regular expression string containing only letters a-z or .. A . 
* means it can represent any one letter.

For example:
addWord("bad")
addWord("dad")
addWord("mad")
search("pad") -> false
search("bad") -> true
search(".ad") -> true
search("b..") -> true


* Note:
* You may assume that all words are consist of lowercase letters a-z. 
*/
/*****************************************************************************/

#include <string>
#include <unordered_map>

using namespace std;

class WordDictionary {
private:
	class wdNode
	{
	public:
		wdNode()
		{
			m_isWord = false;
		}
		bool m_isWord;
		unordered_map<char, wdNode *> m_children;
	};

	void destroyDic(wdNode * node)
	{
		if (node == NULL) return;
		for (auto it = node->m_children.begin(); it != node->m_children.end(); it++)
		{
			destroyDic(it->second);
		}
		delete(node);
	}

	bool findNode_dfs(wdNode * node, const string & word, int level)
	{
		if (level == word.length()) return node->m_isWord;

		char curr = word[level];
		if (curr == '.')
		{
			for (auto child : node->m_children)
			{
				if (findNode_dfs(child.second, word, level + 1)) return true;
			}
			return false;
		}
		else {
			if (!node->m_children.count(curr)) return false;
			else return findNode_dfs(node->m_children[curr], word, level + 1);
		}
		return false;
	}

	wdNode * m_root;

public:
	/** Initialize your data structure here. */
	WordDictionary()
	{
		m_root = new wdNode();
	}

	/** Adds a word into the data structure. */
	void addWord(string word)
	{
		if (word.empty()) return;
		wdNode * node = m_root;
		for (char curr : word)
		{
			if (!node->m_children.count(curr)) node->m_children[curr] = new wdNode();
			node = node->m_children[curr];
		}
		node->m_isWord = true;
	}

	/** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
	bool search(string word)
	{
		return findNode_dfs(m_root, word, 0);
	}

	~WordDictionary()
	{
		destroyDic(m_root);
	}
};

/**
* Your WordDictionary object will be instantiated and called as such:
* WordDictionary obj = new WordDictionary();
* obj.addWord(word);
* bool param_2 = obj.search(word);
*/