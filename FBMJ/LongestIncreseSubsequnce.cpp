/*
 * LongestIncreseSubsequnce.cpp
 *
 *  Created on: Oct 11, 2017
 *      Author: JoanneY1
 */
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>
#include <stack>
#include <queue>

using namespace std;

/*
Given an unsorted array of integers, find the length of longest increasing subsequence.

For example,
Given [10, 9, 2, 5, 3, 7, 101, 18],
The longest increasing subsequence is [2, 3, 7, 101], therefore the length is 4. Note that there may be more than one LIS combination, it is only necessary for you to return the length.

Your algorithm should run in O(n2) complexity.

Follow up: Could you improve it to O(n log n) time complexity?
*/

/*
dp solution that will take O(n^2) time complexity
*/
int lengthOfLIS(vector<int>& nums)
{
  int nlen = nums.size();
  int maxLen = 0;
  vector<int> dp(nlen, 1);
  for(int i=1; i<nlen; i++)
  {
    for(int j=i-1; j>=0; j--)
    {
      if(nums[j] < nums[i]) dp[i] = max(dp[j]+1, dp[i]);
    }
    maxLen = max(maxLen, dp[i]);
  }

  return maxLen;
}

/*
O(nlogn) solution - we keep one vector to log the smallest tail number of possible increasing subsequence
with lenth i, when we meet a new element in the array, we compare it with tails in the vector, if it is
larger than all the values, then increase the length by one.
Ohterwise, we replace the tail with this new tail
*/
int lenOfLIS(vector<int> nums)
{
  vector<int> tails;
  for(int i=0; i<nums.size(); i++)
  {
    auto it = lower_bound(tails.begin(), tails.end(), nums[i]);
    if(it == tails.end()) tails.push_back(nums[i]);
    else *it = nums[i];
  }
  return tails.size();
}


int lenLISBinarySearch(vector<int> nums)
{
  int nlen = nums.size();
  vector<int> tails(nlen);
  int size = 0;
  for(int x : nums)
  {
    int i=0, j=size;
    while(i != j)
    {
      int m = (i+j)/2;
      if(tails[m] < x) i = m+1;
      else j = m;
    }
    tails[i] = x;
    if(i == size) size++;
  }
  return size;
}




