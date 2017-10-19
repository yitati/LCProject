/******************************************************************************
* Question: #29 Divide Two Integers
* company tag: Facebook
* Divide two integers without using multiplication, division and mod operator.
* If it is overflow, return MAX_INT.
* Follow-up:
* company tag: Facebook
* What is the remainder?
*****************************************************************************/

#include <algorithm>
#include <iostream>
#include <climits>

using namespace std;

/*
Given two integers a and b, calculate a / b without using divide/mod operations.
return both the quotient and remainder.

Examples:

0 / 1 = 0

1 / 0 = Integer.MAX_VALUE

-1 / 0 = Integer.MAX_VALUE

11 / 2 = 5

-11 / 2 = -5

11 / -2 = -5

-11 / -2 = -5
*/

pair<int, int> divide(int dividend, int divisor)
{
	if(divisor == 0) return {INT_MAX, 0};
	if(dividend == 0) return {0, 0};

	int sign = (divisor > 0) ^ (dividend > 0) == 1 ? -1 : 1;

	long long did = labs(dividend), div = labs(divisor);
	long long quotient = 0;

	while(did >= div)
	{
		int base = 1;
		while(did >= (div << 1))
		{
			div <<= 1;
			base <<= 1;
		}
		did -= div;
		quotient += base;
		div = labs(divisor);
	}
	quotient *= sign;
	return {quotient, did};
}

// always substract the divisor, but when divisor not large enough, shift it to left
int divide(int dividend, int divisor, int& remainder)
{
    long long result = 0, did = labs(dividend), div = labs(divisor);
    // get sign
    int sign = ((dividend > 0)^(divisor > 0) == 1)? -1 : 1;
    // corner cases, 1.when divisor is 0    2. divident = INT_MAX and divisor = -1
    if(divisor == 0 || (dividend == INT_MIN && divisor == -1)) return INT_MAX;

    while(did >= div)
    {
        int quotient = 1;

        while(div+div < did)
        {
            div <<= 1;   // multiply by 2
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

/*
int main(int argc, char ** argv)
{
	cout << divide(16, 3) << endl;
	cout << divide(0, 1) << endl;
	cout << divide(1, 0) << endl;

	system("pause");
}
*/
