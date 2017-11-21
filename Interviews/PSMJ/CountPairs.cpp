/*
 * PSMJ_CountPairs.cpp
 *
Count how many distinct pairs of i, j (i < j) and nums[j]- nums[i] == diff.
 */

#include <vector>
#include <unordered_set>

using namespace std;
/*
 * use unordred_set
 */
int countPairs(vector<int> array, int diff)
{
	int len = array.size(), pair = 0;
	unordered_set<int> unique;
	for(int num : array)
	{
		int complement = num - diff;
		if(unique.count(complement)) pair++;
		unique.insert(num);
	}
	return pair;
}

/*
 * binary search
 */
bool binarySearch(vector<int>& nums, int start, int end, int target)
{
	if(end < start) return false;
	while(start <= end)
	{
		int mid = start + (end-start)/2;
		if(nums[mid] == target) return true;
		else if(target < nums[mid]) end = mid-1;
		else start = mid+1;
	}
	return false;
}

int countPairBinSearch(vector<int> array, int diff)
{
	int i = 0, len = array.size(), pair = 0;
	while(i < len)
	{
		int num = array[i];
		int target = num + diff;
		if(binarySearch(array, i+1, len-1, target)) pair++;
	}
	return pair;
}


