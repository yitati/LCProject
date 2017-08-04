/*
 * Laicode_MergeKSortedLists.cpp
 *
Merge K sorted lists into one big sorted list in ascending order.

Assumptions

ListOfLists is not null, and none of the lists is null.

 */

#include "ListNode.h"
#include <vector>
#include <queue>

using namespace std;

ListNode* mergeKSortedList(vector<ListNode*> input)
{
	auto comp = [](const ListNode* lhs, const ListNode* rhs)->bool{
		return lhs->val > rhs->val;
	};

	priority_queue<ListNode*, vector<ListNode*>, decltype(comp)> minHeap(comp);

	for(int i=0; i<input.size(); i++)
	{
		if(input[i] == NULL) continue;
		minHeap.push(input[i]);
	}

	ListNode* dummy = new ListNode(0);
	ListNode* curr = dummy;
	while(!minHeap.empty()){
		ListNode* tmp = minHeap.top();
		minHeap.pop();
		curr->next = tmp;
		curr = curr->next;
		tmp = tmp->next;
		if(tmp){
			minHeap.push(tmp);
		}
	}

	curr = dummy->next;
	delete dummy;
	return curr;
}




