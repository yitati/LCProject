/******************************************************************************/
/*
* Question: #367 Valid Perfect Square
* Given a positive integer num, write a function which returns True if num is a perfect square else False.
* Note: Do not use any built-in library function such as sqrt. 
* company tag: LinkedIn

Example 1: 
Input: 16
Returns: True

Example 2: 
Input: 14
Returns: False

*/
/*****************************************************************************/

#include <vector>

using namespace std;

// Same as LC69 Sqrt(x)

// solution 1 - O(sqrt(n)) time
bool isPerfectSquare1(int num)
{
	for (long i = 0; i*i <= num; i++)
	{
		if (i*i == num) return true;
	}
	return false;
}

// solution 2 - O(sqrt(n)) time
// any sqaure number should be equal to 1+3+5+7+9 ...
bool isPerfectSquare2(int num)
{
	int i = 1;
	while (num > 0)
	{
		num -= i;
		i += 2;
	}
	return num == 0;
}

// solution 3 - Binary search O(logn)
bool isPerfectSquare3(int num)
{
	int low = 1, high = num;
	while (low <= high)
	{
		int mid = low + (high - low) / 2;
		long long root = mid*mid;
		if (root == num) return true;
		else if (root > num) low = mid + 1;
		else high = mid - 1;
	}
	return false;
}

// solution 4 - Newton Method
bool isPerfectSquare4(int num)
{
	long x = num;
	while (x*x > num)
	{
		x = (x + num / x) >> 1;
	}
	return x*x == num;
}
