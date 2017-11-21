/******************************************************************************
* Question: #335 Self Crossing
* company tag: eBay
* You are given an array x of n positive numbers. You start at point (0,0) and moves x[0] metres to the north,
* then x[1] metres to the west, x[2] metres to the south, x[3] metres to the east and so on. In other words,
* after each move your direction changes counter-clockwise.
* Write a one-pass algorithm with O(1) extra space to determine, if your path crosses itself, or not. 

Example 1:

Given x = [2, 1, 1, 2],
┌───┐
│   │
└───┼──>
    │

Return true (self crossing)



Example 2:

Given x = [1, 2, 3, 4],
┌──────┐
│      │
│
│
└────────────>

Return false (not self crossing)



Example 3:

Given x = [1, 1, 1, 1],
┌───┐
│   │
└───┼>

Return true (self crossing)


*****************************************************************************/

// TODO - today

#include <vector>

using namespace std;

bool isSelfCrossing(vector<int>& x)
{
	for (int i = 3; i<x.size(); i++)
	{
		if (x[i] >= x[i - 2] && x[i - 1] <= x[i - 3]) return true;
		else if (i > 3 && x[i - 1] == x[i - 3] && x[i - 4] + x[i] >= x[i - 2]) return true;
		else if (i > 4 && x[i] + x[i - 4] >= x[i - 2] && x[i - 1] + x[i - 5] >= x[i - 3] && x[i - 1] <= x[i - 3] && x[i - 4] <= x[i - 2]) return true;
	}

	return false;
}

/*
 * http://buttercola.blogspot.com/2016/06/leetcode-335-self-crossing.html
 * consider the cases that there is no self crossing, totally 3 cases
 * 1. Only have internal spiral. In this case, the length of each step should go smaller and smaller. So we only
 * 	  need to check if x[i] < x[i-2] (shrinking spiral)
 * 2. Only have external spiral. In this case, the length of each step should go larger and larger. So we only
 *    need to check if x[i] > x[i-2] (growing spiral)
 * 3. In the third case, it goes external spiral first then go internal. In this case, the trick part is we may
 *    need to update the base of the internal squirrel (shrinking spiral inside of the growing spiral)
 */
bool isSelfCrossing2(vector<int>& x)
{
	if(x.empty() || x.size() < 4) return false;

	// start from the 3rd length
	int i = 2;

	// case 1 : outside spiral
	while(i < x.size() && x[i] > x[i-2])
	{
		i++;
	}
	if(i == x.size()) return false;

	// case 2: transit to inside spiral
	if(i >= 4 && x[i] + x[i-4] >= x[i-2] || i == 3 && x[i] == x[i-2])
	{
		x[i-1] -= x[i-3];
	}
	i++;

	// case 3: internal spiral
	while(i < x.size() && x[i] < x[i-2])
	{
		i++;
	}

	return i != x.size();
}

