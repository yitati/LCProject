/******************************************************************************/
/*
* Question: #371 Sum of Two Integers
* Calculate the sum of two integers a and b, but you are not allowed to use the operator + and -.
Example:
Given a = 1 and b = 2, return 3. 
*/
/*****************************************************************************/

int getSum(int a, int b)
{
	int result = 0, carry = 0, mask = 1;
	for (int i = 0; i < 32; i++)
	{
		int opt1 = (a&mask) == mask ? 1 : 0;
		int opt2 = (b&mask) == mask ? 1 : 0;
		result |= (opt1^opt2^carry) << i;
		carry = (carry&&opt1) || (carry && opt2) || (opt1 && opt2);
		mask <<= 1;
	}
	return result;
}