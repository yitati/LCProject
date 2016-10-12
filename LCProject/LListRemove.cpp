/******************************************************************************/
/**
* Question: #203 Remove Linked List Elements
* Remove all elements from a linked list of integers that have value val.
* Example
* Given: 1 -> 2 -> 6 -> 3 -> 4 -> 5 -> 6, val = 6
* Return: 1 -> 2 -> 3 -> 4 -> 5
*/
/*****************************************************************************/

#include <iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode * next;
	ListNode(int x) : val(x), next(NULL) {}
};

class ListRemove {
public:
	ListNode* removeElements(ListNode* head, int val) {
		if (head == NULL) return head;
		ListNode * dummy = new ListNode(val - 1);
		dummy->next = head;
		ListNode * ptr = dummy;
		while (ptr->next)
		{
			if (ptr->next->val == val)
			{
				ListNode * tmp = ptr->next;
				ptr->next = tmp->next;
				delete tmp;
			}
			else
			{
				ptr = ptr->next;
			}
		}

		return dummy->next;
	}
};

/*
int main(int argv, char * argr[])
{
	ListRemove remove;

	ListNode * head = new ListNode(1);

	ListNode * node1 = new ListNode(2);
	head->next = node1;

	ListNode * node4 = new ListNode(2);
	node1->next = node4;

	ListNode * node2 = new ListNode(3);
	node4->next = node2;

	ListNode * node3 = new ListNode(4);
	node2->next = node3;


	ListNode* ptr = head;
	cout << "fist print" << endl;
	while (ptr)
	{
		cout << ptr->val << " ";
		ptr = ptr->next;
	}
	cout << endl;

	head = remove.removeElements(head, 2);

	ptr = head;
	cout << "second print" << endl;
	while (ptr)
	{
		cout << ptr->val << " ";
		ptr = ptr->next;
	}
	cout << endl;

	system("pause");

}
*/