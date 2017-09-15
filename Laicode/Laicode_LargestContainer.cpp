/*
 * Laicode_LargestContainer.cpp
 *
Given an array of non-negative integers, each of them representing the height of a board perpendicular to the horizontal line,
the distance between any two adjacent boards is 1. Consider selecting two boards such that together with the horizontal line
they form a container. Find the volume of the largest such container.

Assumptions

The given array is not null and has size of at least 2
Examples

{ 2, 1, 3, 1, 2, 1 }, the largest container is formed by the two boards of height 2, the volume of the container is 2 * 4 = 8.
 */

#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

/*
 * 1. O(n^2) solution
 */
int largestContainer1(vector<int> array)
{
	int maxCont = 0;
	for(int i=0; i<array.size(); i++)
	{
		for(int j=0; j<array.size(); j++)
		{
			maxCont = max(maxCont, min(array[i], array[j])* abs(j-i));
		}
	}
	return maxCont;
}

/*
 * 2. O(n) solution, first set lhs and rhs to be the two terminals, and move whoever is smaller
 */
int largestContainer2(vector<int> array)
{
	int lhs = 0, rhs = array.size()-1;
	int maxCont = 0;
	while(lhs < rhs)
	{
		maxCont = max(maxCont, (rhs-lhs)*min(array[lhs], array[rhs]));
		if(array[lhs] < array[rhs]) lhs++;
		else rhs--;
	}
	return maxCont;
}

