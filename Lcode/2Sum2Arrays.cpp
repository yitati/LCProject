/*
 * 2Sum2Arrays.cpp
 *

Given two arrays A and B, determine whether or not there exists a pair of elements,
one drawn from each array, that sums to the given target number.

Assumptions

The two given arrays are not null and have length of at least 1
Examples

A = {3, 1, 5}, B = {2, 8}, target = 7, return true(pick 5 from A and pick 2 from B)

A = {1, 3, 5}, B = {2, 8}, target = 6, return false

 */

#include <vector>
#include <unordered_set>

using namespace std;

/*
 * two sum using hashset, suppose one of them is larger with size m and the other is shorter with size n,
 * then we store all the elements in larger to a hash set and loop through each element in shorter, if we
 * see a complementary match in the set, then we find the result, time complexity should be O(nlogm).
 */
bool existSum(vector<int> a, vector<int> b, int target)
{
	const vector<int>& longer = a.size() > b.size() ? a : b;
	const vector<int>& shorter = a.size() < b.size() ? a : b;

	unordered_set<int> unique;
	for(int num : longer) unique.insert(num);

	for(int num : shorter)
	{
		int complement = target - num;
		if(unique.count(complement)) return true;
	}
	return false;
}



