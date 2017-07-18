/******************************************************************************/
/*
* Question: #350 Intersecton of Two Arrays II
* Given two arrays, write a function to compute their intersection. 

Example:
Given nums1 = [1, 2, 2, 1], nums2 = [2, 2], return [2, 2]. 

* Note:
* Each element in the result should appear as many times as it shows in both arrays.
* The result can be in any order.
* Follow up:
* What if the given array is already sorted? How would you optimize your algorithm?
* - then use two pointers just like intersectionII.
*
* What if nums1's size is small compared to nums2's size? Which algorithm is better?
* - unordered_map to store the frequency of nums1 (the shorter one) and find intersection in nums2.
*   time complexity is O(m+n) and space complexity is O(n) (smaller number)
*
* What if elements of nums2 are stored on disk, and the memory is limited such that you 
* cannot load all elements into the memory at once?
* - store unordered_map for nums1 and check nums2
*/
/*****************************************************************************/

#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

vector<int> intersectionII(vector<int>& nums1, vector<int>& nums2)
{
    // sort the two arrays
    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());
    vector<int> result;
    int i = 0, j = 0;
    while(i < nums1.size() && j < nums2.size())
    {
        if(nums1[i] < nums2[j]) i++;
        else if(nums1[i] > nums2[j]) j++;
        else
        {
            result.push_back(nums1[i]);
            i++;
            j++;
        }
    }
    return result;
}

vector<int> intersect(vector<int>& nums1, vector<int>& nums2) 
{
	if (nums1.size() > nums2.size()) return intersect(nums2, nums1);
	vector<int> result;
	unordered_map<int, int>table;
	for (int i = 0; i < nums1.size(); i++)
	{
		table[nums1[i]]++;
	}
	for (int i = 0; i < nums2.size(); i++)
	{
		if (table.count(nums2[i]))
		{
			table[nums2[i]]--;
			result.push_back(nums2[i]);
			if (table[nums2[i]] == 0)
			{
				table.erase(nums2[i]);
			}
		}
	}
	return result;
}
