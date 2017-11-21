/******************************************************************************
* Question: #211 Add and Search Word - Data structure design
* company tag: Facebook
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
*****************************************************************************/

#include <string>
#include <unordered_map>

using namespace std;

class WordDictionary {
public:
    class TrieNode
    {
    public:
        vector<TrieNode*> children;
        bool isWord;

        TrieNode()
        {
            children = vector<TrieNode*>(26, NULL);
            isWord = false;
        }
    };

    // root for the trie
    TrieNode* root;

    /** Initialize your data structure here. */
    WordDictionary()
    {
        root = new TrieNode();
    }

    bool findNode(string& word, int level, TrieNode * node)
    {
    	if(level == word.length()) return node->isWord;
    	char c = word[level];
    	if(c == '.')
    	{
    		for(int i=0; i<26; i++)
    		{
    			if(!node->children[i]) continue;
    			if(findNode(word, level+1, node->children[i]) == true) return true;
    		}
    	}
    	else
    	{
    		if(!node->children[c-'a']) return false;
    		return findNode(word, level+1, node->children[c-'a']);
    	}
    	return false;
    }

    /** Adds a word into the data structure. */
    void addWord(string word)
    {
        TrieNode* curr = root;
        for(char c : word)
        {
            int idx = c-'a';
            if(!curr->children[idx])
            {
                curr->children[idx] = new TrieNode();
            }
            curr = curr->children[idx];
        }
        curr->isWord = true;
    }

    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word)
    {
        return findNode(word, 0, root);
    }
};

/**
* Your WordDictionary object will be instantiated and called as such:
* WordDictionary obj = new WordDictionary();
* obj.addWord(word);
* bool param_2 = obj.search(word);
*/

