#pragma once

/* In C++ STL we have priority_queue, which is a Max heap. To use the priority_queue as min heap,
*  we need to tweak the comparator operator used by the library.
*  In MaxHeap comparator should return true if a<b but for Min hep it should return false.
*/

#include <queue>
#include <iostream>

using namespace std;

struct comparator {
	bool operator()(int i, int j)
	{
		return i > j;
	}
};

// priority_queue<int, std::vector<int>, comparator> minHeap;
