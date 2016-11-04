/******************************************************************************/
/**
* Question: #206 Reverse Linked List
* Reverse a singly linked list.
*/
/*****************************************************************************/


#include <iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode * next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode* reverseList(ListNode* head) 
{
	if (head == NULL || head->next == NULL) return head;

	ListNode * dummy = new ListNode(0);
	dummy->next = head;

	ListNode * curr = head;
	while (curr->next != NULL)
	{
		ListNode * tmp = curr->next;
		curr->next = tmp->next;
		dummy->next = tmp;
		tmp->next = head;
		head = tmp;
	}

	delete dummy;
	return head;
}

/*
int main(int argv, char * argr[])
{

	ListNode * node1 = new ListNode(1);

	ListNode * node2 = new ListNode(2);
	node1->next = node2;

	//ListNode * node3 = new ListNode(3);
	//node2->next = node3;

	//ListNode * node4 = new ListNode(4);
	//node3->next = node4;

	ListNode* ptr = node1;
	cout << "fist print" << endl;
	while (ptr)
	{
		cout << ptr->val << " ";
		ptr = ptr->next;
	}
	cout << endl;


	node1 = reverseList(node1);
	ptr = node1;
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
