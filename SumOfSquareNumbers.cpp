/***************************************************************************************************
 * Question #633 Sum Of Square Numbers
 * company tag: LinkedIn
 * type tag: #binary search#
 * Given a non-negative integer c, your task is to decide whether there're two integers a and b
 * such that a2 + b2 = c.

Example 1:

Input: 5
Output: True
Explanation: 1 * 1 + 2 * 2 = 5


Example 2:

Input: 3
Output: False

****************************************************************************************************/

#include <cmath>

using namespace std;

bool judgeSquareSum(int c)
{
	if(c < 0) return false;
	int lhs = 0, rhs = sqrt(c);
	while(lhs <= rhs)
	{
		int curr = lhs*lhs + rhs*rhs;
		if(curr == c) return true;
		if(curr < c) lhs++;
		else rhs--;
	}
	return false;
}
