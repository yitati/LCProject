/******************************************************************************/
/**
 * Question: #171 Excel Sheet Column Number
 * Related to question Excel Sheet Column Title
 * Given a column title as appear in an Excel sheet, return its corresponding column number.

 For example:
 
 A -> 1
 B -> 2
 C -> 3
 ...
 Z -> 26
 AA -> 27
 AB -> 28
 */
/*****************************************************************************/

#include <string>

using namespace std;

int titleToNumber(string s)
{
    int sum = 0, len = s.length();
    for(int i=0; i < len; i++)
    {
        int x = s[i]-'A'+ 1;
        sum = sum * 26 + x;
    }
    return sum;
}
