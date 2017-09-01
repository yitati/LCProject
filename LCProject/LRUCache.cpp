/******************************************************************************
* Question: #146 LRU Cache
* company tag: Salseforce, Facebook, eBay
* Design and implement a data structure for Least Recently Used (LRU) cache. 
* It should support the following operations: get and put. 
* get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
* put(key, value) - Set or insert the value if the key is not already present. When the cache reached its capacity, 
* it should invalidate the least recently used item before inserting a new item. 
* Follow up:
* company tag: Facebook
* Could you do both operations in O(1) time complexity?
* company tag: Salseforce
* How to better design for template? How to better design put(k, v) and get(k) to handle error?
* How to design the LRU so it can be thread-safe?
*****************************************************************************/

#include <unordered_map>

using namespace std;

struct biListNode {
	// we have to have this key, otherwise don't know which key to delete
	int key;
	int val;
	biListNode * prev;
	biListNode * next;
	biListNode() : prev(NULL), next(NULL) {};
};

class LRUCache {
public:
	LRUCache(int capacity)
	{
		m_size = 0;
		m_capacity = capacity;

		m_dummyHead = new biListNode();
		m_dummyTail = new biListNode();
		m_dummyHead->next = m_dummyTail;
		m_dummyTail->prev = m_dummyHead;
	}

	~LRUCache() {
		for (auto it = m_dict.begin(); it != m_dict.end(); it++) {
			delete it->second;
		}
		delete m_dummyHead;
		delete m_dummyTail;
	}

	int get(int key)
	{
		if (!m_dict.count(key)) return -1;
		biListNode * targetNode = m_dict[key];
		if (m_dummyHead->next != targetNode)
		{
			removeNode(targetNode);
			addToHead(targetNode);
		}
		return targetNode->val;
	}

	void put(int key, int value)
	{
		if (get(key) != -1) {
			m_dict[key]->val = value;
			return;
		}

		if (m_size == m_capacity)
		{
			removeTail();
			m_size--;
		}
		biListNode * newNode = new biListNode();
		newNode->key = key;
		newNode->val = value;
		addToHead(newNode);
		m_dict[key] = newNode;
		m_size++;
	}

private:
	unordered_map<int, biListNode *> m_dict;
	biListNode * m_dummyHead;
	biListNode * m_dummyTail;
	int m_capacity;
	int m_size;

	void removeNode(biListNode * node)
	{
		biListNode * pre = node->prev;
		biListNode * nxt = node->next;
		pre->next = nxt;
		nxt->prev = pre;
	}

	void addToHead(biListNode * node)
	{
		node->prev = m_dummyHead;
		node->next = m_dummyHead->next;
		m_dummyHead->next->prev = node;
		m_dummyHead->next = node;
	}

	void removeTail()
	{
		biListNode * res = m_dummyTail->prev;
		removeNode(res);
		m_dict.erase(res->key);
		delete res;
	}
};


