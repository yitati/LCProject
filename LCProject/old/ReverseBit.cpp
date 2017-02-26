/******************************************************************************/
/**
* Question: #7 Reverse Integer
* Reverse digits of an integer
*
* Question: #190 Reverse Bits
* Reverse bits of a given 32 bits unsigned integer.
* Follow up:
* If this funciton is called many times, how would you optimize it?
* Related problem: Reverse Integer
*
/*****************************************************************************/

#include <iostream>

using namespace std;


class Reverse {
public:
	int reverseInt(int x)
	{
		if (x == 0) return 0;
		int sum = 0;
		while (x)
		{
			sum = sum * 10 + x % 10;
			x = x / 10;
		}
		return sum;
	}

	uint32_t reverseBits(uint32_t n)
	{
		uint32_t result = 0;
		uint32_t key = 1, bit = 0;
		int i = 0;
		for (i = 0; i<32; i++)
		{
			// get the ith bit
			result = (result << 1) + (n >> i & 1);
		}
		return result;

	}
};

/*
int main(int argc, char * argv)
{
	uint32_t n = 43261596;
	int x = 123;

	Reverse reverse;
	cout << reverse.reverseInt(x) << endl; // result should be 321
	cout << reverse.reverseBits(n) << endl; // result should be 964176192

	system("pause");

	return 0;
}
*/

