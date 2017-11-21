/******************************************************************************/
/*
* Question: #381 Insert Delete GetRandom II O(1)
* Design a data structure that supports all following operations in average O(1) time.

* Note: Duplicate elements are allowed.
* insert(val): Inserts an item val to the collection.
* remove(val): Removes an item val from the collection if present.
* getRandom: Returns a random element from current collection of elements. The probability of each element being returned is linearly related to the number of same value the collection contains.

Example:

// Init an empty collection.
RandomizedCollection collection = new RandomizedCollection();

// Inserts 1 to the collection. Returns true as the collection did not contain 1.
collection.insert(1);

// Inserts another 1 to the collection. Returns false as the collection contained 1. Collection now contains [1,1].
collection.insert(1);

// Inserts 2 to the collection, returns true. Collection now contains [1,1,2].
collection.insert(2);

// getRandom should return 1 with the probability 2/3, and returns 2 with the probability 1/3.
collection.getRandom();

// Removes 1 from the collection, returns true. Collection now contains [1,2].
collection.remove(1);

// getRandom should return 1 and 2 both equally likely.
collection.getRandom();
*/
/*****************************************************************************/

/**
* Your RandomizedSet object will be instantiated and called as such:
* RandomizedSet obj = new RandomizedSet();
* bool param_1 = obj.insert(val);
* bool param_2 = obj.remove(val);
* int param_3 = obj.getRandom();
*/

#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class RandomizedCollection {
public:

	vector<int> m_arr;
	unordered_map<int, unordered_set<int>> m_table;

	/** Initialize your data structure here. */
	RandomizedCollection() {}

	/** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
	bool insert(int val)
	{
		bool notExist = m_table.find(val) == m_table.end();
		m_table[val].insert(m_arr.size());
		m_arr.push_back(val);
		return notExist;
	}

	/** Removes a value from the set. Returns true if the set contained the specified element. */
	bool remove(int val)
	{
		if (m_table.find(val) == m_table.end()) return false;
		else
		{
			// remove the first one
			int index = *m_table[val].begin();
			m_table[val].erase(index);
			if (m_table[val].empty()) m_table.erase(val);
			if (index != m_arr.size() - 1) {
				swap(m_arr[index], m_arr[m_arr.size() - 1]);
				m_table[m_arr[index]].erase(m_arr.size() - 1);
				m_table[m_arr[index]].insert(index);
			}
			m_arr.pop_back();

		}
		return true;
	}

	/** Get a random element from the set. */
	int getRandom()
	{
		if (m_arr.size())
		{
			int index = rand() % m_arr.size();
			return m_arr[index];
		}
		return -1;
	}
};