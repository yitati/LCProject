/******************************************************************************/
/*
* Question: #233 Number of Digit One
* Given an integer n, count the total number of digit 1 appearing in all non-negative integers less than or equal to n.

For example:
 Given n = 13,
 Return 6, because digit 1 occurred in the following numbers: 1, 10, 11, 12, 13. 

* Hint:
* 1.Beware of overflow.

*/
/*****************************************************************************/


int countDigitOne(int n)
{
	if (n <= 0) return 0;
	else if (n < 10) return 1;
	else
	{
		long long base = 10;
		while (n / (base * 10))
		{
			base *= 10;
		}
		if (n / base == 1)
		{
			return n%base + 1 + countDigitOne(base - 1) + countDigitOne(n%base);
		}
		else
		{
			return countDigitOne(base - 1)*(n / base) + base + countDigitOne(n%base);
		}
	}
}