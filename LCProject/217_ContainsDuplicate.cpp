/******************************************************************************/
/*
* Question: #217 Contains Duplicate
* Given an array of integers, find if the array contains any duplicates. 
* Your function should return true if any value appears at least twice in the array, 
* and it should return false if every element is distinct.
*/
/*****************************************************************************/

#include <vector>
#include <unordered_set>

using namespace std;

bool containsDuplicate(vector<int>& nums) 
{
	unordered_set<int> visited;
	for (int num : nums)
	{
		if (visited.find(num) != visited.end()) return true;
		else visited.insert(num);
	}
	return false;
}