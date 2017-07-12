/********************************************************************************************
 * Question #633 Sum of Square Numbers
 * Given a non-negative integer c, your task is to decide whether there're two integers a and
 * b such that a^2 + b^2 = c

Example 1:

Input: 5
Output: True
Explanation: 1 * 1 + 2 * 2 = 5

Example 2:

Input: 3
Output: False

 ********************************************************************************************/

#include <cmath>

bool judgeSquareSum(int c)
{
	// binary search solution
	if (c < 0)
		return false;
	int lhs = 0, rhs = sqrt(c);
	while (lhs <= rhs)
	{
		int curr = lhs * lhs + rhs * rhs;
		if (curr == c)
			return true;
		else if (curr < c)
			lhs++;
		else
			rhs--;
	}
	return false;
}



