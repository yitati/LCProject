/******************************************************************************/
/**
* Question: #19 Remove Nth Node From End Of List
* Given a linked list, remove the nth node from the end of list and return its head.
For example,
Given linked list: 1->2->3->4->5, and n = 2.
After removing the second node from the end, the linked list becomes 1->2->3->5.
* Note:
* Given n will always be valid.
* Try to do this in one pass.
/*****************************************************************************/

#include "../Leetcode/ListNode.h"

using namespace std;

// one path solution - keep a fast pointer and a slow pointer
// keep the distance between them to be n+1
ListNode* removeNthFromEnd(ListNode* head, int n) 
{
    if(!head) return NULL;
    ListNode* dummy = new ListNode(0);
    dummy->next = head;
    ListNode* fast = dummy;
    ListNode* slow = dummy;
    while(n >= 0 && fast)
    {
        fast = fast->next;
        n--;
    }
    while(fast)
    {
        slow = slow->next;
        fast = fast->next;
    }
    ListNode* toDelete = slow->next;
    slow->next = toDelete->next;
    delete toDelete;
    head = dummy->next;
    delete dummy;
    return head;
}

/*
int main(int argc, char ** argv)
{
	int input1[] = { 1, 2, 3, 4, 5 }; // size is 3
	int n1 = 5;

	ListNode * l1 = generateList(input1, n1);

	ListNode * result = removeNthFromEnd(l1, 2);

	printList(result);

	system("pause");
}
*/
