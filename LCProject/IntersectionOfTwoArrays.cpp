/******************************************************************************
* Question: #349 Intersecton of Two Arrays
* Given two arrays, write a function to compute their intersection.

Example:
Given nums1 = [1, 2, 2, 1], nums2 = [2, 2], return [2].

* Note:
* Each element in the result must be unique.
* The result can be in any order.
*****************************************************************************/

#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

bool binSearchFind(int target, vector<int> & nums)
{
	int lhs = 0, rhs = nums.size() - 1;
	while (lhs <= rhs)
	{
		int mid = lhs + (rhs - lhs) / 2;
		if (nums[mid] == target) return true;
		else if (target > nums[mid]) lhs = mid + 1;
		else rhs = mid - 1;
	}
	return false;
}

// could use hash map / binary search / sort and use two pointers 
vector<int> findDuplicateInArrays(vector<int> & shortNum, vector<int> & longNum)
{
	unordered_set<int> result;
	int lenShort = shortNum.size();
	int lenLong = longNum.size();
	sort(longNum.begin(), longNum.end());
	for (int target:shortNum)
	{
		if (binSearchFind(target, longNum) == true)
		{
			result.insert(target);
		}
	}

	vector<int> final;
	for (int num : result)
	{
		final.push_back(num);
	}

	return final;
}

vector<int> intersection(vector<int>& nums1, vector<int>& nums2)
{
	int len1 = nums1.size();
	int len2 = nums2.size();
	if (len1 > len2) return findDuplicateInArrays(nums2, nums1);
	else return findDuplicateInArrays(nums1, nums2);
}
