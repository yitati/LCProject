/*************************************************************/
/*
 * Question: #136 Single Number
 * Given an array of integers, every element appears twice except for one. Find that single one.
 * Note:
 * Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory.
 */
/***********************************************************/

#include <vector>

using namespace std;

int singleNumber(vector<int> & nums)
{
    int result = 0;
    for(int i=0; i<nums.size(); i++)
    {
        result ^= nums[i];
    }
    return result;
}
