/******************************************************************************
* Question: #23 Merge K Sorted Lists
* company tag: Facebook, LinkedIn
* Merge k sorted linked lists and return it as one sorted list.
* Analyze and describe its complexity.
*****************************************************************************/

#include <queue>
#include "../Leetcode/ListNode.h"

using namespace std;

// optimal
ListNode* mergeKListsWithLambda(vector<ListNode*>& lists)
{
    auto comp = [](const ListNode* lhs, const ListNode* rhs)->bool{
      return lhs->val > rhs->val;
    };

    priority_queue<ListNode*, vector<ListNode*>, decltype(comp)> minHeap(comp);
    ListNode* dummy = new ListNode(0);
    ListNode* curr = dummy;

    for(auto list : lists)
    {
        if(list) minHeap.push(list);
    }

    while(!minHeap.empty())
    {
        ListNode* tmp = minHeap.top();
        minHeap.pop();
        curr->next = tmp;
        if(tmp->next) minHeap.push(tmp->next);
        curr = tmp;
        curr->next = NULL;
    }

    curr = dummy->next;
    delete dummy;
    return curr;
}

 // Solution : Use recursion, divide & conquer
 ListNode * mergeLists(vector<ListNode*>& lists, int start, int end)
 {
	 if (start > end) return NULL;
	 if (start == end) return lists[start];

	 int mid = start + (end - start) / 2;
	 ListNode * lhs = mergeLists(lists, start, mid);
	 ListNode * rhs = mergeLists(lists, mid + 1, end);

	 return mergeTwoLists(lhs, rhs);
 }

ListNode* mergeKLists(vector<ListNode*>& lists) {
	if (lists.empty()) return NULL;
	return mergeLists(lists, 0, lists.size() - 1);
}

// Solution 2 : Use Min Heap
// 2_1: Create a class to include node and override compator less function
// 2_2: Create a functor and override the Comp class
// 2_3: Create lambda comp class, use auto keyword

// This is the defination of priority queue
//template<class T, class Container = std::vector<T>, class Compare = std::less<typename Container::value_type>> 
//class priority_queue;

// for the less function, 
// return true - lower priority - put behind
// return false - higer priority - put faward

// Solution 2_1: Create a class and override the comparator less function
class ListNodeInfo
{
public:
	ListNode * node;
	ListNodeInfo() : node(NULL) {};
	ListNodeInfo(ListNode * root) : node(root) {};
	bool operator<(const ListNodeInfo & rhs) const
	{
		return node->val > rhs.node->val;
	}
};

priority_queue<ListNodeInfo> minHeap1;

// Solution 2_2: Create a functor and replace the less function
class MyComp
{
public:
	bool operator()(const ListNode * lhs, const ListNode * rhs)
	{
		return lhs->val > rhs->val;
	}
};

MyComp comp;
priority_queue<ListNode*, vector<ListNode*>, MyComp> minHeap2(comp);

// push the head of the K lists to the heap, always pop the min one and push it's next
ListNode* mergeKLists_Heap2(vector<ListNode*>& lists)
{
	if (lists.empty()) return NULL;
	if (lists.size() == 1) return lists[0];

	ListNode * dummy = new ListNode(-1);
	ListNode * ptr = dummy;
	ListNode * curr = NULL;

	for (int i = 0; i < lists.size(); i++)
	{
		minHeap2.push(lists[i]);
	}

	while (minHeap2.size())
	{
		curr = minHeap2.top();
		minHeap2.pop();
		if (curr->next)
		{
			minHeap2.push(curr->next);
		}
		ptr->next = curr;
		ptr = curr;
	}

	ptr = dummy->next;
	delete dummy;
	return ptr;
}





