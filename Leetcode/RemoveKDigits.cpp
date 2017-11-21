/******************************************************************************
* Question: #402 Remove K Digits
* Given a non-negative integer num represented as a string, remove k digits from the number
* so that the new number is the smallest possible.
*
* Note:
* The length of num is less than 10002 and will be ≥ k.
* The given num does not contain any leading zero.
*
Example 1:
Input: num = "1432219", k = 3
Output: "1219"
Explanation: Remove the three digits 4, 3, and 2 to form the new number 1219 which is the smallest.

Example 2:
Input: num = "10200", k = 1
Output: "200"
Explanation: Remove the leading 1 and the number is 200. Note that the output must not contain
leading zeroes.

Example 3:
Input: num = "10", k = 2
Output: "0"
Explanation: Remove all the digits from the number and it is left with nothing which is 0.

*****************************************************************************/

#include <string>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

// this is a greedy problem
// as long as the next number is smaller and we can make enough char then replace the last one
// this is similar to get the smallest value of fixed length string
string removeKdigits(string num, int k)
{
	if((int)num.length() <= k) return "0";
    string result;
    for(int i=0; i<num.length(); i++)
    {
    	while(!result.empty() && result.back() > num[i] && k > 0)
    	{
    		result.pop_back();
    		k--;
    	}
    	result.push_back(num[i]);
    }
    while(k > 0 && !result.empty())
    {
    	result.pop_back();
    	k--;
    }
    // check for all 0's
    int i = 0;
    while(i < result.size() && result[i] == '0') i++;
    return i == result.length() ? "0" : result.substr(i);
}

/*
int main(int argc, char ** argv)
{
	cout << removeKdigits("1432219", 3) << endl;  // 1219
	cout << removeKdigits("10200", 1) << endl;  //200
	cout << removeKdigits("10", 2) << endl;  // 0
	cout << removeKdigits("1112", 1) << endl; // 111
	cout << removeKdigits("10", 1) << endl;  // 1
	cout << removeKdigits("1234567890", 9) << endl;  // 0
}
*/





