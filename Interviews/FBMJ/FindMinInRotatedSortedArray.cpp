/*
 * FindMinInRotatedArray.cpp
 *
 *  Created on: Oct 7, 2017
 *      Author: JoanneY1
 */

#include <vector>

using namespace std;

int findMin(vector<int>& nums)
{
    if (nums.empty()) return -1;
    int lhs = 0, rhs = nums.size() - 1, minVal = nums[lhs];
    while (lhs < rhs)
    {
        int mid = lhs + (rhs - lhs) / 2;
        if (nums[mid] < nums[rhs])
        {
            rhs = mid;
        }
        else lhs = mid + 1;
    }
    return nums[lhs];
}


