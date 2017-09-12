/*
 * AllOneSet.cpp
 * O(1) Set
 * Question: Implement set with integers in range [1...N], implements five operations, add, remove, contains,
 * clear, iterate. There are 2 versions to solve this -
 * v1: using only bucket array with size N+1.
 * v2: using only sequential array (store them sequentially in array)
 * v3: achieve best of v1 and v2.
 * The time complexity of above solutions are
 *                          add      remove    contains    clear    iterate
 *   bucket array           O(1)     O(1)      O(1)        O(1)     O(N)
 *   sequential array       O(1)     O(count)  O(count)    O(1)     O(count)
 *   best of two            O(1)     O(1)      O(1)        O(1)     O(count)
 *
 *   The solution is to use the give two arrays. For bucket array value (set), it will be the index in
 *   the sequential array.
 *   Thisng to notice:
 *   1) How to remove one element from the array?
 *   - swap the last element in the array with the one to remove, and reduce the size
 *   2) How to clear? clear the array and start size from 0
 *
 */
// similar to FastMap
#include <vector>

using namespace std;

class FastSet
{
public:
	FastSet(int N)
	{
		m_set = vector<int>(N, -1);
	}

	void add(int num)
	{
		if(this->contains(num)) return;
		int index = m_array.size();
		m_array.push_back(num);
		m_set[num] = index;
	}

	bool contains(int num)
	{
		if(m_set[num] < 0) return false;
		else if(m_set[num] > m_array.size())
		{
			m_set[num] = -1; // here we set the index to -1 to indicate removed element
			return false;
		}
		int index = m_set[num];
		return m_array[index] == num;
	}

	void remove(int num)
	{
		if(!contains(num)) return;
		int index = m_set[num];
		m_set[num] = -1;
		//swap the element to remove with the last one
		int lastIdx = m_array.size();
		int lastNum = m_array.back();
		swap(m_array[index], m_array[lastIdx]);
		m_set[lastNum] = index;
		m_array.pop_back();
	}

	void clear()
	{
		m_array.clear();
	}

	vector<int> iterate(){
		vector<int> res;
		for(int num : m_array)
		{
			res.push_back(num);
		}
		return res;
	}

private:
	vector<int> m_set;
	vector<int> m_array;
};




