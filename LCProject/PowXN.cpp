/******************************************************************************
* Question: #50 PowXN
* company tag:Facebook, LinkedIn, eBay
* Implement pow(x, n).
*****************************************************************************/

#include <algorithm>

double myPow_recursion(double x, int n)
{
	if (n == 0) return 1;
	if (n == 1) return x;
	double result = myPow_recursion(x, n / 2);
	return (n % 2 == 0) ? result * result : result * result * x;
}

double myPow(double x, int n) 
{
	double result = myPow_recursion(x, abs(n));
	if (n < 0) return 1 / result;
	return result;
}
