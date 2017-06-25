/******************************************************************************/
/*
* Question: #88 Merge Sorted Array
* Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.
* Note:
* You may assume that nums1 has enough space (size that is greater or equal to m+n) to hold addtional elements from nums2.
* The number of elements initialized in nums1 and nums2 are m and n respectively.
*/
/*****************************************************************************/

#include <iostream>
#include <vector>
#include <climits>

using namespace std;
// move the smaller one
// since we cannot use extra space so put elements from the end of the queue
void mergeSortedArray(vector<int>& nums1, int m, vector<int>& nums2, int n) {
	if (m <= n) mergeSortedArray(nums2, n, nums1, m);
	int k = m + n - 1, i = m - 1, j = n - 1;
	while (i >= 0 || j >= 0)
	{
		int opt1 = i >= 0 ? nums1[i] : INT_MIN;
		int opt2 = j >= 0 ? nums2[j] : INT_MIN;
		if (opt1 >= opt2)
		{
			nums1[k--] = nums1[i--];
		}
		else
		{
			nums1[k--] = nums2[j--];
		}
	}
}

/*
int main(int argc, char ** argv)
{
	int input1[] = { 1, 3, 5, 7, 9 };
	int n1 = 5;
	vector<int> nums1(10);
	for (int i = 0; i < n1; i++)
	{
		nums1[i] = input1[i];
	}

	int input2[] = { 2, 4, 6, 8 };
	int n2 = 4;
	vector<int> nums2(input2, input2 + sizeof(input2) / sizeof(int));

	mergeSortedArray(nums1, 5, nums2, 4);

	for (int i = 0; i < n1+n2; i++)
	{
		cout << nums1[i] << "   ";
	}

	cout << endl;

	system("pause");
}
*/
