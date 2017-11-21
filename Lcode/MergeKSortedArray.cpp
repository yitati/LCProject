/*
 * Laicode_MergeKSortedArray.cpp
Merge K sorted array into one big sorted array in ascending order.

Assumptions

The input arrayOfArrays is not null, none of the arrays is null either.
 */

#include <vector>

using namespace std;

typedef vector<int>::const_iterator IterType;

class IterPairComp{
public:
	bool operator()(const pair<IterType, IterType>& lhs, const pair<IterType, IterType>& rhs) const
	{
		return *lhs.first > *rhs.first;
	}
};

/*
vector<int> mergeKSortedArrays(vector<vector<int> > arrayOfArrays)
{
	IterPairComp comp;
	priority_queue<pair<IterType, IterType>, vector<pair<IterType, IterType>>, IterPairComp> minHeap(comp);

	vector<int> result;

	// push the int and its
	for(int i=0; i<arrayOfArrays.size(); i++)
	{
		if(arrayOfArrays[i].empty()) continue;
		minHeap.emplace(arrayOfArrays[i].begin(), arrayOfArrays[i].end());
	}

	while(!minHeap.empty())
	{
		auto item = minHeap.top();
		minHeap.pop();
		result.push_back(*item.first);
		item.first++;
		if(item.first < item.second){
			minHeap.push(item);
		}
	}

	return result;
}
*/


