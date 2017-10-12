/*
 * AddStrings.cpp
 *
Given two non-negative integers num1 and num2 represented as string, return the sum of num1 and num2.

Note:

The length of both num1 and num2 is < 5100.
Both num1 and num2 contains only digits 0-9.
Both num1 and num2 does not contain any leading zero.
You must not use any built-in BigInteger library or convert the inputs to integer directly.

http://www.1point3acres.com/bbs/forum.php?mod=viewthread&tid=291594&extra=page%3D1%26filter%3Dsortid%26sortid%3D311%26searchoption%5B3046%5D%5Bvalue%5D%3D2%26searchoption%5B3046%5D%5Btype%5D%3Dradio%26sortid%3D311
 */

#include <string>

using namespace std;

// not in place
string addStrings(string num1, string num2)
{
    int i = num1.size() - 1;
    int j = num2.size() - 1;
    int carry = 0;
    string res = "";
    while(i>=0 || j>=0 || carry){
        long sum = 0;
        if(i >= 0){sum += (num1[i] - '0');i--;}
        if(j >= 0){sum += (num2[j] - '0');j--;}
        sum += carry;
        carry = sum / 10;
        sum = sum % 10;
        res =  res + to_string(sum);
    }
    reverse(res.begin(), res.end());
    return res;
}

string addStringsInplace(string num1, string num2) {
	// keep the longer one in front
	if (num1.length() < num2.length()) return addStrings(num2, num1);
	reverse(num1.begin(), num1.end());
	reverse(num2.begin(), num2.end());
	int i = 0, j = 0, carry = 0;
	while (i < num1.length()) {
		int sum = num1[i] - '0' + (j < num2.length() ? num2[j++] - '0' : 0) + carry;
		num1[i++] = sum % 10 + '0';
		carry = sum / 10;
	}
	if (carry > 0) num1.push_back('1');
	reverse(num1.begin(), num1.end());
	return num1;
}


