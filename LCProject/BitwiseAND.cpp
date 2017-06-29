/******************************************************************************/
/**
* Question: #201 Bitwise AND of Numbers Range
* Given a range [m, n] where 0 <= m <= n <= 2147483647, return the bitwise AND of all numbers in this range, inclusive.
* For example, given the range [5, 7], you should return 4.
*/
/*****************************************************************************/

class Solution {
public:
	int rangeBitwiseAnd(int m, int n) {
		if (m == 0) return 0;
		int bit = 0;
		while (m != n)
		{
			m >>= 1;
			n >>= 1;
			bit++;
		}

		return m << bit;
	}
};