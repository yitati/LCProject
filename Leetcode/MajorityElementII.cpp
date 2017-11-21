/******************************************************************************/
/**
* Question: #229 Majority Element II
* Given an integer array of size n, find all elements that appear more than n/3 times. The algorithm
* should run in linear time and in O(1) space.
*
*/
/*****************************************************************************/

#include <vector>

using namespace std;

// similar to majority element
// there will be at most two such majority elements
vector<int> majorityElementII(vector<int>& nums)
{
    vector<int> major;
    int major1 = 0, major2 = 1, count1 = 0, count2 = 0;
    for(int num : nums)
    {
        if(num == major1) count1++;
        else if(num == major2) count2++;
        else if(count1 == 0)
        {
            major1 = num;
            count1++;
        }
        else if(count2 == 0)
        {
            major2 = num;
            count2++;
        }
        else
        {
            count1--;
            count2--;
        }

    }
    count1 = 0;
    count2 = 0;
    for(int num : nums)
    {
        if(num == major1) count1++;
        if(num == major2) count2++;
    }

    if(count1 > nums.size()/3) major.push_back(major1);
    if(count2 > nums.size()/3) major.push_back(major2);

    return major;
}
