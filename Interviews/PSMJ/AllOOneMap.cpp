/*
 * AllOOneMap.cpp
 *

设计一个Map<Integer, Integer>，满足下面的复杂度:
add: O(1)  deletion: O(1)  lookup: O(1)  clear:O(1)  iterate: O(number of elements)

Time complexity:
                      vector              Map
add                   O(1)                O(1)
search                O(n)                O(n)
delete                O(n)                O(1)
clear                 O(1)                O(n)
iterate               O(n)                O(n)

so we can combine the two data structure to get all O(1) complexity operation.

map<key, index>
vector<pair<key, value>>

*/

#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

class FastMap
{
public:
	FastMap(){}

	void add(int key, int val)
	{
		if(m_map.count(key) && m_map[key] < m_array.size()) // if this key already exist
		{
			int index = m_map[key];
			m_array[index].second = val; // update the value
		}
		else
		{
			m_map[key] = m_array.size();
			m_array.emplace_back(key, val); // insert the new key value pair
		}
	}

	int search(int key)
	{
		if(!m_map.count(key)) return -1;
		else if(m_map[key] > m_array.size())
		{
			m_map.erase(key);
			return -1;
		}
		int index = m_map[key];
		return m_array[index].second;
	}

	void remove(int key)
	{
		if(!m_map.count(key)) return;
		else if(m_map[key] > m_array.size())
		{
			m_map.erase(key);
			return;
		}

		int index = m_map[key];
		m_map.erase(key);
		// deal with the array
		int lastIdx = m_array.size()-1;
		int lastKey = m_array[lastIdx].first;
		swap(m_array[index], m_array[lastIdx]);
		m_array.pop_back();
		m_map[lastKey] = index;
	}

	void clear()
	{
		m_array.clear();
	}

	void traversal()
	{
		for(int i=0; i<m_array.size(); i++)
		{
			cout << "key is " << m_array[i].first << "   val is "<< m_array[i].second << endl;
		}
	}

private:
	vector<pair<int, int>> m_array;  // vector that stores the key-value pair
	unordered_map<int, int> m_map;   // map stores the key-index pair
};




