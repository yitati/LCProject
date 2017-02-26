/******************************************************************************/
/*
* Question: #29 Divide Two Integers
* Divide two integers without using multiplication, division and mod operator.
* If it is overflow, return MAX_INT.
*/
/*****************************************************************************/

#include <algorithm>
#include <iostream>

using namespace std;

// always substract the divisor, but when divisor not large enough, shift it to left
int divide(int dividend, int divisor) 
{
	long long result = 0, did = labs(dividend), div = labs(divisor);
	int sign = ((dividend > 0) ^ (divisor > 0) == 0) ? 1 : -1;
	if (!divisor || (dividend == INT_MIN && divisor == -1)) return INT_MAX;
	int quotient = 1;
	while (did >= div)
	{
		while (div+div < did)
		{
			div <<= 1;
			quotient += quotient;
		}
		result += quotient;
		did -= div;
		quotient = 1;
		div = abs(divisor);
	}
	
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