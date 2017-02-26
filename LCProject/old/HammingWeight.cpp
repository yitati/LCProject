/******************************************************************************/
/** BIT MANIPULATION
* Question: #191 Number of 1 Bits
* Write a function that takes an unsigned integer and returns the number of '1'
* bits that it has (also known as Hanmming weight)
* For example, the 32-bit integer '11' has binary representation
*
* 00000000000000000000000000001011
*
* so the funciton should return 3.
/*****************************************************************************/

#include <iostream>

using namespace std;


class HammingWeight {
public:
	int hammingWeight(uint32_t n) 
	{
		int numOfBits = 32;
		int i, count = 0;
		for (i = 0; i < numOfBits; i++)
		{
			if (n & 1) count++;
			n >>= 1;
		}
		return count;
	}
};

/*
int main(int argc, char * argv)
{
	HammingWeight hamming;
	cout << hamming.hammingWeight(11) << endl;
	return 0;
}
*/
