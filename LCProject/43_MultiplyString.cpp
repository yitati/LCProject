/******************************************************************************/
/*
* Question: #43 Multiply String
* Given two non-negative integers num1 and num2 represented as strings, return the product of num1 and num2.
* Note:
* The length of both num1 and num2 is < 110.
* Both num1 and num2 contains only digits 0-9.
* Both num1 and num2 does not contain any leading zero.
* You must not use any built-in BigInteger library or convert the inputs to integer directly.
*/
/*****************************************************************************/

#include <string>
#include <iostream>

using namespace std;

string multiply(string num1, string num2) 
{
	int len1 = num1.length(), len2 = num2.length();
	string result(len1+len2, '0');
	int i, j, k = 0, carry = 0;
	for (i = len1-1; i >= 0; i--)
	{
		carry = 0;
		for (j = len2-1; j >= 0; j--)
		{
			int sum = (result[i+j+1]-'0') + (num1[i] - '0')*(num2[j] - '0') + carry;
			result[i+j+1] = sum % 10 + '0';
			carry = sum / 10;
		}
		result[i] = carry + '0';
	}
	while (k < len1+len2-1 && result[k] == '0') k++;
	result.erase(0, k);
	return result;
}

int main(int argc, char ** argv)
{
	cout << multiply1("123", "456") << endl;
	system("pause");
}