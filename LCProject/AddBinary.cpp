/******************************************************************************
 * Question: #67 Add Binary
 * company tag: Facebook
 * Given two binary strings, return their sum (also a binary string).
 For example,
 a = "11"
 b = "1"
 Return "100".
 * Follow-up:
 * What if we have K such binary to add ?
 * What if base does not equal to 2?
*****************************************************************************/

#include <string>

using namespace std;

string addBinary(string a, string b)
{
    int len1 = a.length(), len2 = b.length(), BASE = 2;
    if(len2 > len1) return addBinary(b, a);
    string result(len1 + 1, '0');
    int carry = 0;
    for(int i=len1-1, j=len2-1; i>=0; i--, j--)
    {
        int opt1 = a[i]-'0';
        int opt2 = j < 0 ? 0 : b[j]-'0';
        int sum = opt1 + opt2 + carry;
        carry = sum / BASE;
        sum %= BASE;
        result[i+1] = sum+'0';
    }
    result[0] = carry+'0';
    int i = 0;
    while(i < len1 && result[i] == '0') i++;
    return result.substr(i);
    
}
