/******************************************************************************
* Question: #35 Search Insert Postion
* company tag: LinkedIn
* Given a sorted array and a target value, return the index if the target is found. 
* If not, return the index where it would be if it were inserted in order.

* You may assume no duplicates in the array.

Here are few examples.
[1,3,5,6], 5 → 2
[1,3,5,6], 2 → 1
[1,3,5,6], 7 → 4
[1,3,5,6], 0 → 0
*****************************************************************************/

#include <iostream>
#include <vector>

using namespace std;
// BST to find the closest neibours
int searchInsert(vector<int>& nums, int target) {
    int lhs = 0, rhs = nums.size()-1;
    while(lhs < rhs){
        int mid = lhs + (rhs-lhs)/2;
        if(target > nums[mid]) lhs = mid+1;
        else rhs = mid;
    }
    if(nums[lhs] >= target) return lhs;
    else return nums.size();
}

int searchInsert_simple(vector<int>& nums, int target)
{
	auto it = lower_bound(nums.begin(), nums.end(), target);
	return distance(nums.begin(), it);
}
