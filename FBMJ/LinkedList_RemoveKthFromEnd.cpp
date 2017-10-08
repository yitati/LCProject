/*
 * LinkedList_RemoveKthFromEnd.cpp
 *
 *  Created on: Oct 7, 2017
 *      Author: JoanneY1
 */

#include "../LCProject/ListNode.h"

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



