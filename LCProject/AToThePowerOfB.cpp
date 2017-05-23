/*
Evaluate a to the power of b, assuming both a and b are integers and b is non-negative.

Examples
power(2, 0) = 1
power(2, 3) = 8
power(0, 10) = 0
power(-2, 5) = -32

Corner Cases
What if the result is overflowed? We can assume the result will not be overflowed when we 
solve this problem on this online judge.
*/

long power(int a, int b)
{
	if (a == 0) return 0;
	if (b == 0) return 1;
	long long half = power(a, b / 2);
	return b % 2 == 0 ? half * half : half * half * a;
}