/******************************************************************************
* Question: #208 Implement Trie (Prefix Tree)
* company tag: Facebook
* Implement trie with insert, search, and startsWith methods.
* Note: You may assume that all inputs are consist of lowercase letters a-z.
*****************************************************************************/

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
#include <unordered_map>

using namespace std;
// Asuumption: use 26 lowercase english character
class Trie {
private:
	class TrieNode
	{
	public:
		TrieNode()
		{
			m_isWord = false;
		}

		bool m_isWord;
		unordered_map<char, TrieNode*> m_children;

	};

	void destroyTrie(TrieNode * node)
	{
		if (node == NULL) return;
		for (auto it = node->m_children.begin(); it != node->m_children.end(); it++)
		{
			destroyTrie(it->second);
		}
		delete(node);
	}

	TrieNode * findNode(const string & word)
	{
		if (word.empty()) return NULL;
		TrieNode * node = m_root;
		for (char curr : word)
		{
			if (!node->m_children.count(curr))
			{
				return NULL;
			}
			else node = node->m_children[curr];
		}
		return node;
	}

	TrieNode * m_root;

public:
	/** Initialize your data structure here. */
	Trie()
	{
		m_root = new TrieNode();
	}

	/** Inserts a word into the trie. */
	void insert(string word)
	{
		if (word.empty()) return;
		TrieNode * node = m_root;
		for (char curr : word)
		{
			if (!node->m_children.count(curr))
			{
				node->m_children[curr] = new TrieNode();
			}
			node = node->m_children[curr];
		}
		node->m_isWord = true;
	}

	/** Returns if the word is in the trie. */
	bool search(string word)
	{
		TrieNode * node = findNode(word);
		if (!node) return false;
		return node->m_isWord;
	}

	/** Returns if there is any word in the trie that starts with the given prefix. */
	bool startsWith(string prefix)
	{
		TrieNode * node = findNode(prefix);
		if (!node) return false;
		return true;
	}

	/** Destructor to delete the whole trie **/
	~Trie()
	{
		destroyTrie(m_root);
	}
};

