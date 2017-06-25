/******************************************************************************/
/*
* Question: #4 Median of Two Sorted Arrays
* There are two sorted arrays nums1 and nums2 of size m and n respectively.
* Find the median of the two sorted arrays. The overall run time complexity should be O(log(m+n)).
* Example 1:
* nums1 = [1, 3]
* nums2 = [2]
* The median is 2.0
* 
* Example 2:
* nums1 = [1, 2]
* nums2 = [3, 4]
* The median is (2+3)/2 = 2.5
*/
/*****************************************************************************/
 
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

/* Solution 1 : binary search idea*/
// find kth min from two sorted array
int findKthMin(const vector<int>& nums1, int lhs1, const vector<int>& nums2, int lhs2, int k)
{
	// if nums1 is empty()
	if (lhs1 >= nums1.size()) return nums2[lhs2 + k - 1];
	// if nums2 is empty()
	if (lhs2 >= nums2.size()) return nums1[lhs1 + k - 1];
	// base case
	if (k == 1) return min(nums1[lhs1], nums2[lhs2]);

	int mid1 = lhs1 + k / 2 - 1 < nums1.size() ? nums1[lhs1 + k / 2 - 1] : INT_MAX;
	int mid2 = lhs2 + k / 2 - 1 < nums2.size() ? nums2[lhs2 + k / 2 - 1] : INT_MAX;

	if (mid1 <= mid2)
	{
		// descard the first k/2 elements in nums1
		return findKthMin(nums1, lhs1 + k / 2, nums2, lhs2, k - k / 2);
	}
	else
	{
		// descard the first k/2 elements in nums2
		return findKthMin(nums1, lhs1, nums2, lhs2 + k / 2, k - k / 2);
	}
}

// for a sorted array- 
// median = nums[n/2]  - n is odd
// median = (nums[n/2] + nums[n/2+1])/2 - n is even
double findMedianSortedArrays(vector<int> & nums1, vector<int> & nums2) {
	int totalNum = nums1.size() + nums2.size();
	if (totalNum % 2 == 1) {
		return findKthMin(nums1, 0, nums2, 0, totalNum / 2 + 1);
	}
	else {
		double sum = findKthMin(nums1, 0, nums2, 0, totalNum / 2) + findKthMin(nums1, 0, nums2, 0, totalNum / 2 + 1);
		return 0.5 * sum;
	}
}


double medianOfArray(vector<int>& nums, int start, int end)
{
	if (end < start) return 0;
	int n = end - start + 1;
	int idx = start + (end - start) / 2;
	double res;
	if (n % 2 == 0)
	{
		res = ((double)nums[idx] + (double)nums[idx + 1]) / 2;
	}
	else
	{
		res = (double)nums[idx];
	}
	return res;
}


/*
int main(int argc, char ** argv)
{
	int input1[] = { 1, 3, 5, 7, 9 };
	int input11[] = {1, 3, 5, 7, 9, 11};
	int input2[] = { 2, 4, 6, 8, 10 };

	vector<int>nums1(input1, input1 + sizeof(input1) / sizeof(int));
	vector<int>nums11(input11, input11 + sizeof(input11) / sizeof(int));
	vector<int>nums2(input2, input2 + sizeof(input2) / sizeof(int));

	cout << "result for input 1 and input 2" << endl;
	cout << findMedianSortedArrays(nums1, nums2) << endl << endl; // expect 5.5

	cout << "result for input 11 and input 2" << endl;
	cout << findMedianSortedArrays(nums11, nums2) << endl << endl; // expect 6


	vector<int> nums3;
	vector<int> nums4(1, 1);

	vector<int> nums41(2);
	nums41[0] = 2;
	nums41[1] = 3;

	cout << "result for input 3 and input 4" << endl;
	cout << findMedianSortedArrays(nums3, nums4) << endl << endl; // expect 1

	cout << "result for input 3 and input 41" << endl;
	cout << findMedianSortedArrays(nums3, nums41) << endl << endl; // expect 2.5000

	int input5[] = {1, 2};
	int input51[] = { 1, 2, 2 };
	int input52[] = { 1, 2, 3 };

	int input6[] = {1, 2, 3};
	int input61[] = { 1, 1 };

	vector<int>nums5(input5, input5 + sizeof(input5) / sizeof(int));
	vector<int>nums51(input51, input51 + sizeof(input51) / sizeof(int));
	vector<int>nums52(input52, input52 + sizeof(input52) / sizeof(int));
	vector<int>nums6(input6, input6 + sizeof(input6) / sizeof(int));
	vector<int>nums61(input61, input61 + sizeof(input61) / sizeof(int));
	
	cout << "result for input 5 and input 6" << endl;
	cout << findMedianSortedArrays(nums5, nums6) << endl << endl;  // expect 2

	cout << "result for input 5 and input 61" << endl;
	cout << findMedianSortedArrays(nums5, nums61) << endl << endl;  // expect 1

	cout << "result for input 51 and input 6" << endl;
	cout << findMedianSortedArrays(nums51, nums6) << endl << endl; // expect 2

	cout << "result for input 52 and input 6" << endl;
	cout << findMedianSortedArrays(nums52, nums6) << endl << endl; // expect 2


	int input7[] = {1, 2};
	int input8[] = {1, 2};
	vector<int>nums7(input7, input7 + sizeof(input7) / sizeof(int));
	vector<int>nums8(input8, input8 + sizeof(input8) / sizeof(int));
	cout << "result for input 7 and input 8" << endl;
	cout << findMedianSortedArrays(nums7, nums8) << endl << endl;  // expect 1.5000

	system("pause");
}
*/
