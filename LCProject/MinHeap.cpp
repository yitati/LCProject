#include "MinHeap.h"

using namespace std;

struct comparator {
	bool operator()(int i, int j)
	{
		return i > j;
	}
};

priority_queue<int, std::vector<int>, comparator> minHeap;