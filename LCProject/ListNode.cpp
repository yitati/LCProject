#include "ListNode.h"


void printList(ListNode * head)
{
	if (head == NULL)
	{
		cout << "Null List" << endl;
	}
	ListNode * curr = head;
	cout << "List Content:" << endl;
	while (curr != NULL)
	{
		cout << curr->val << "  ";
		curr = curr->next;
	}
	cout << endl;
}

ListNode * generateList(int arr[], int arr_size)
{
	ListNode * head = NULL;
	ListNode * curr = head;
	for (int i = 0; i<arr_size; i++)
	{
		if (head == NULL)
		{
			head = new ListNode(arr[i]);
			curr = head;
		}
		else
		{
			ListNode * newNode = new ListNode(arr[i]);
			curr->next = newNode;
			curr = curr->next;
		}
	}

	printList(head);

	return head;
}

ListNode * generateList(vector<int>& arr)
{
	ListNode * head = NULL;
	ListNode * curr = head;
	int arr_size = arr.size();
	for (int i = 0; i<arr_size; i++)
	{
		if (head == NULL)
		{
			head = new ListNode(arr[i]);
			curr = head;
		}
		else
		{
			ListNode * newNode = new ListNode(arr[i]);
			curr->next = newNode;
			curr = curr->next;
		}
	}

	printList(head);

	return head;
}
