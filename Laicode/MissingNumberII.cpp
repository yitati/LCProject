/*
 * Laicode_MissingNumberII.cpp
 *

Given an integer array of size N - 1 sorted by ascending order, containing all the numbers from 1 to N except one,
find the missing number.

Assumptions

The given array is not null, and N >= 1
Examples

A = {1, 2, 4}, the missing number is 3
A = {1, 2, 3}, the missing number is 4
A = {}, the missing number is 1

 */

/*
 * put every number in the right place except the missing one
 */

#include <vector>

using namespace std;

int missingII(vector<int> array)
{
	for(int i=0; i<array.size(); i++)
	{
		if(array[i] != i+1) return i+1;
	}
	return array.size()+1;
}




