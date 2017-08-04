/*
 * Laicode_2Sum.cpp

Determine if there exist two elements in a given array, the sum of which is the given target number.

Assumptions

The given array is not null and has length of at least 2
​Examples

A = {1, 2, 3, 4}, target = 5, return true (1 + 4 = 5)

A = {2, 4, 2, 1}, target = 4, return true (2 + 2 = 4)

A = {2, 4, 1}, target = 4, return false

 */


#include <vector>
#include <unordered_set>

using namespace std;

// solution 1 - use hash map, time complexity is O(n)
bool existSum_set(vector<int> array, int target)
{
	unordered_set<int> nums;
	for(int num : array){
		int tofind = target-num;
		if(nums.count(tofind)) return true;
		nums.insert(num);
	}
	return false;
}




