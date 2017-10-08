#include <algorithm>
#include <iostream>
#include <climits>

using namespace std;

/*
 *  Math_DivideTwoIntegers.cpp
 *
 * Divide two integers without using multiplication, division and mod operator.
 * If it is overflow, return MAX_INT.
 * Also we need to know the remainder
 */


/*
 * the brutal force way: keep substract divisor in dividend until div <= div, but this take
 * O(k) time, if k is the quotient
 */

/*
 * since we cannot use mutiplication or division or mod, then we can only use
 * addtion and substraction.
 * everytime we do -
 * 1. if did > div + div, keep adding div to itself(shifting left by 1, double it self)
 *    then the quotient should be doubled too, then we get 2n*div <= did <= 4*n*div
 * 2. then we got quotient should be at least n, then we need to narrow down in [n*div, 2*n div]
 *    by using the same trick
 */
int divide(int dividend, int divisor, int& remainder)
{
	int sign = (dividend > 0)^(divisor > 0) ? -1 : 1;
	long long did = labs(dividend), div = labs(divisor);
	int result = 0;

	// corner case, when divisor is 0 or if result overflow
	if(divisor == 0) return INT_MAX;
	if(dividend == INT_MAX && divisor == -1) return INT_MAX;

	while(did >= div)
	{
		int quotient = 1;

		while(did > (div + div))
		{
			div <<= 1;
			quotient <<= 1;
		}

		result += quotient;
		did -= div;
		div = labs(divisor);
	}

	remainder = did;
	result *= sign;
	return result;

}



