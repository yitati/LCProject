/*
 * LinkedList_ReversePrint.cpp
 */


#include <iostream>
#include <../LCProject/ListNode.h>
#include <stack>

using namespace std;

/*
 * solution 1 - recursion
 */
void reversePrintLinkedList_recursion(ListNode* head)
{
	if(head->next)
	{
		reversePrintLinkedList_recursion(head->next);
	}
	cout << head->val << "   ";
}

/*
 * solution 2 - use a stack
 */
void reversePrintLinkedList_stack(ListNode* head)
{
	ListNode* curr = head;
	stack<int> table;
	while(curr)
	{
		table.push(curr->val);
		curr = curr->next;
	}

	while(!table.empty())
	{
		cout << table.top() << "   ";
		table.pop();
	}
}


