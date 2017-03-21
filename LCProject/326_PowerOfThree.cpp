/******************************************************************************/
/*
* Question: #329 Power of Three
* Given an integer, write a function to determine if it is a power of three. 
* Follow up:
* Could you do it without using any loop / recursion? 
*/
/*****************************************************************************/

#include <algorithm>

bool isPowerOfThree(int n)
{
	if (n <= 0) return false;
	long long x = 1;
	while (x <= n)
	{
		if (x == n) return true;
		x *= 3;
	}
	return false;
}