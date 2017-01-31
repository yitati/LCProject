/******************************************************************************/
/*
* Question: #66 Plus One
* Given a non-negative integer represented as a non-empty array of digits, plus one to the integer.

* You may assume the integer do not contain any leading zero, except the number 0 itself.

The digits are stored such that the most significant digit is at the head of the list.

*/
/*****************************************************************************/
#include <vector>

using namespace std;

vector<int> plusOne(vector<int>& digits)
{
	int carry = 0, sum = 0;
	for (int i = digits.size() - 1; i >= 0; i--)
	{
		if (i == digits.size() - 1) sum = digits[i] + 1;
		else sum = digits[i] + carry;
		digits[i] = sum % 10;
		carry = sum / 10;
	}
	if (carry != 0) digits.insert(digits.begin(), carry);
	return digits;
}