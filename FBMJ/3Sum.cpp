/*
 * 3Sum.cpp
 *
 *  Created on: Oct 9, 2017
 *      Author: JoanneY1
 */

#include <vector>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

using namespace std;

/*
 * 3SUM，不能sort。刚开始用brute force做了个n^3的。
 * 后来在小哥的提示下，先把数组转换成set，然后最后一遍扫的时候直接看在不在set里。这样降到n^2

make a unordered_map<int, unordered_set<int>> to store all the value and index collection
*/

vector<vector<int>> threeSumNoSort(vector<int> array, int target)
{
  unordered_map<int, unordered_set<int>> table;
  vector<vector<int>> results;
  for(int i=0; i<array.size(); i++)
  {
    table[array[i]].insert(i);
  }

  for(int i=0; i<array.size(); i++)
  {
    // remove this index from table
    table[array[i]].erase(i);
    for(int j=i+1; j<array.size(); j++)
    {
      table[array[j]].erase(j);
      int sum = array[i] + array[j];
      int comp = target - sum;
      if(table.count(comp) && !table[comp].empty())
      {
        vector<int> result = {array[i], array[j], comp};
        results.push_back(result);
      }
      table[array[j]].insert(j);
    }
    table[array[i]].insert(i);
  }

  return results;
}


// normal 3 sum, sort and calculate
vector<vector<int>> threeSum(vector<int>& nums)
{
	int n = nums.size();
	if (n < 3) return{};
	vector<vector<int>> results;
	sort(nums.begin(), nums.end());
	for (int index = 0; index < n - 2; index++)
	{
		if (index > 0 && nums[index] == nums[index - 1]) continue;
		int target = 0 - nums[index];
		int i = index + 1, j = n - 1;
		while (i < j)
		{
			if (nums[i] + nums[j] == target)
			{
				vector<int> result = {nums[index], nums[i], nums[j]};
				results.push_back(result);
				i++;
				j--;
				while (i<j && nums[i] == nums[i - 1]) i++;
				while (i<j && nums[j] == nums[j + 1]) j--;
			}
			else if (nums[i] + nums[j] < target) i++;
			else j--;
		}
	}
	return results;
}
