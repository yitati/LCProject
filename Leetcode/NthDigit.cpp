/******************************************************************************/
/*
* Question: #400 Nth Digit
* Find the nth digit of the infinite integer sequence 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ... 
* Note:
* n is positive and will fit within the range of a 32-bit signed integer (n < 231). 

Example 1: 
Input:
3

Output:
3

Example 2: 
Input:
11

Output:
0

Explanation:
The 11th digit of the sequence 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ... is a 0, which is part of the number 10.

*/
/*****************************************************************************/

// 3-step to find the digit
// 1. find the length of the number
// 2. find which number it is 
// 3. find which digit it is 
// num of digits in len = 9 * 10^(len-1) * len
int findNthDigit(int n)
{
	int len = 1;
	long long base = 1, count = 9;
	int num = 0, digit = 0, result = 0;
	// find the length
	while (n > count)
	{
		n -= count;
		len++;
		count = count * 10 * len / (len - 1);
		base *= 10;
	}

	// find the number
	num = base + (n - 1) / len;
	digit = (n - 1) % len;

	// find the digit
	for (int i = 0; i <= digit && base > 0; i++)
	{
		result = num / base;
		num %= base;
		base /= 10;
	}
	return result;
}