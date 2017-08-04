/*
 * Laicode_3Sum.cpp

Determine if there exists three elements in a given array that sum to the given target number.
Return all the triple of values that sums to target.

Assumptions

The given array is not null and has length of at least 3
No duplicate triples should be returned, order of the values in the tuple does not matter
Examples

A = {1, 2, 2, 3, 2, 4}, target = 8, return [[1, 3, 4], [2, 2, 4]]

 */

#include <vector>
#include <algorithm>

using namespace std;


vector<vector<int>> threeSum(vector<int> array, int target)
{
	vector<vector<int>> results;
	if(array.size() < 3) return results;
	sort(array.begin(), array.end());

	for(int i=0; i<array.size(); i++)
	{
		if(i>0 && array[i] == array[i-1]) continue;
		int lhs = i+1, rhs = array.size()-1;
		while(lhs < rhs){
			int sum = array[i] + array[lhs] + array[rhs];
			if(sum == target){
				vector<int> result = {array[i], array[lhs], array[rhs]};
				results.push_back(result);
				lhs++;
				rhs--;
				while(lhs < rhs && array[lhs] == array[lhs-1]) lhs++;
				while(lhs < rhs && array[rhs] == array[rhs+1]) rhs++;
			}
			else if(sum < target){
				lhs++;
			}
			else rhs--;
		}
	}

	return results;
}
