/******************************************************************************/
/*
* Question: #208 Implement Trie (Prefix Tree)
* Implement trie with insert, search, and startsWith methods.
* Note: You may assume that all inputs are consist of lowercase letters a-z.
*/
/*****************************************************************************/

/*
Trie: 
- the actual key, is associated with the "path from the root" to an arbitrary node, instead of 
  associated with the nodes directly
- the edges are associated with distinct characters, meaning "what is the possible next char"
- the key is string or sequence typed

Question: suppose we are designing a dictionary, what data structure/container should we use.

- fist find the use case and required operation
   - search
   - delete
   - add
   - find all words with given prefix (auto-detection/fill)

- find the complexities of each operation
  N - # of words
  M - length of the string/word
  K - number of words sharing the same prefix
                                   search                delete				  add				findAllPrefix
  - HashMap                        O(M)                  O(M)                 O(M)			    O(MN)
  - Binary Search Tree			   O(MlogN)				 O(MlogN)		`	  O(MlogN)		    O(MlogN) + K
  - Sorted Array				   O(MlogN)			     O(MlogN) + O(N)	  O(MlogN) + O(N)   O(MlogN) + K

  Trie's benifit:
  - Trie						   O(M)					 O(M)				  O(M)				O(MK)

  Time: search, insert, delete
  - Looking up data in a trie is faster in the worst case, O(M) time (where M is the length of a search string)
  - hashmap - remember, we may need to calculate the hashCode() and compare equals, and that is O(m).
  - ArrayList(sorted) - O(logN) * O(M)
  - Binary Search Tree - O(logN) * O(M)

  Ordering:
  - A trie can provide an alphabetical ordering of the entries by key. why?
	class TrieNode {
		char c-> c-'a'
		// suppose we have 26 characters, each character mapped to one of the index
		(length 26) TrieNode[] children; Map<Char, TrieNode> children;
		boolean isEnd;
		// other information
		}

  - Sorted Array  - YES
  - HashMap - NO
  - Binary Search Tree - YES

  Space:
  - if the trie is not tooo sparse, since resuing the common prefix as many as possible, less space required.
  worst case O(MN) but usually much better than this.


  Drawback:
  Time:  1) if sotred on disk, more random disk accesses(very expensive)
  Space: 1) Every TrieNode has extra space consumtion -> extra space usage
	     2) Memory allocation fragmentation especially when Trie is sparse (not may common prefix)

  Use case:
  - string or sequence typed elements
  - fast search/add/delete
  - grouping common prefix, both for time/space
  - problems related to prefix
*/

#include <string>
#include <vector>
#include <map>

using namespace std;
// Asuumption: use 26 lowercase english character
class TrieNode {
public:
	// Initialize your data structure here.
	TrieNode() {
		m_isWord = false;
	}
	bool m_isWord;
	map<char, TrieNode*> m_children;
};

class Trie {
public:
	Trie() {
		root = new TrieNode();
	}

	// Inserts a word into the trie.
	void insert(string word) // similar to search
	{
		if (word.empty()) return;
		int i;
		TrieNode * node = root;
		for (i = 0; i < word.size(); i++)
		{
			char curr = word[i];
			if (node->m_children.find(curr) == node->m_children.end()) // found the char
			{
				node->m_children[curr] = new TrieNode();
			}			
			node = node->m_children[curr];
		}
		node->m_isWord = true;
	}

	// Returns if the word is in the trie.
	bool search(string word) 
	{
		if (word.empty()) return false;
		int i;
		TrieNode * node = root;
		for (i = 0; i < word.size() && node != NULL; i++)
		{
			char curr = word[i];
			if (node->m_children.find(curr) != node->m_children.end()) // found the char
			{
				node = node->m_children[curr];
			}
			else
			{
				return false;
			}
		}
		return node->m_isWord;
	}

	// Returns if there is any word in the trie
	// that starts with the given prefix.
	bool startsWith(string prefix) // same with search
	{
		if (prefix.empty()) return root == NULL;
		int i;
		TrieNode * node = root;
		for (i = 0; i < prefix.size() && node != NULL; i++)
		{
			char curr = prefix[i];
			if (node->m_children.find(curr) != node->m_children.end()) // find the char
			{
				node = node->m_children[curr];
			}
			else
			{
				return false;
			}
		}
		return !node->m_isWord || !node->m_children.empty();
	}  

	void remove(string word)
	{

	}

	bool remove_helper(string word, int index)
	{
		// find children from curr layer
		
	}

private:
	TrieNode * root;
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");