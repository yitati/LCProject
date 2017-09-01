/******************************************************************************
 * Question: #168 Excel Sheet Column Title
 * company tag: eBay
 * Given a positive integer, return its corresponding column title as appear in an Excel sheet.
 For example:
 1 -> A
 2 -> B
 3 -> C
 ...
 26 -> Z
 27 -> AA
 28 -> AB
*****************************************************************************/

#include <stdio.h>
#include <string>

using namespace std;

string convertToTitle(int n)
{
    string result;
    long long num = n;
    while(num)
    {
        char x = (num+25)%26 + 'A';
        result.insert(result.begin(), x);
        num = (num-1)/26;
    }
    return result;
}
