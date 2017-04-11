/*
Count set bits in an integer
*/

// Simple Method 
// Loop through all bits in an integer, check if a bit is set and if it is then increment the set bit count.
unsigned int countSetBits1(unsigned int n)
{
	unsigned int count = 0;
	while (n)
	{
		count += n & 1;
		n >>= 1;
	}
	return count;
}

// Brian Kernighan's Algorithm
// Substact a number by 1 and do bitwise & with itself (n&(n-1)), we unset the rightmost set bit.
unsigned int countSetBits2(unsigned int n)
{
	unsigned int count = 0;
	while (n)
	{
		n &= (n - 1);
		count++;
	}
	return count;
}
