/*
 * EBMJ_MergeNSortedArray.cpp
 *
 *  Created on: Aug 18, 2017
 *      Author: JoanneY1
 */

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// today

/*
 * solution:
 * use a minheap to store N elements from each array, but except for the value we also need to store the index of array
 * and also which array it is from. So to simplify the problem, will put intrator to the heap
 */

typedef vector<int>::iterator intIter;
vector<int> mergeNSortedArray(vector<vector<int>>& nums)
{
	vector<int> order;
    //lambda comparator
	auto comp = [&](const pair<intIter, intIter>& lhs, const pair<intIter, intIter>& rhs)->bool{
		return *lhs.first > *rhs.first;
	};
	priority_queue<pair<intIter, intIter>, vector<pair<intIter, intIter>>, decltype(comp)> minHeap(comp);

	// fill the heap with N iterator
	for(auto array : nums)
	{
		if(array.empty()) continue;
		minHeap.push(make_pair(array.begin(), array.end()));
	}

	while(!minHeap.empty())
	{
		order.push_back(*minHeap.top().first);
		auto top = minHeap.top();
		minHeap.pop();
		top.first++;
		if(top.first != top.second)
		{
			minHeap.push(make_pair(top.first, top.second));
		}
	}

	return order;
}

/*
int main(int argc, char ** argv)
{
	vector<vector<int>> nums = {{23, 4, 645, 322, 43}, {63, 89, 4, 12, 67}, {12, 44}};
	vector<int> result = mergeNSortedArray(nums);
	for(int i=0; i<result.size(); i++)
	{
		cout << result[i] << "   ";
	}
	cout << endl;
}
*/


