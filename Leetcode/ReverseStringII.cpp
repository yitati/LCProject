/**************************************************************************
 * Question #541. Reverse String II
 * Given a string and an integer k, you need to reverse the first k characters for
 * every 2k characters counting from the start of the string. If there are less than
 * k characters left, reverse all of them. If there are less than 2k but greater than
 * or equal to k characters, then reverse the first k characters and left the other
 * as original.
 * Restrictions:
 * 1. The string consistes of lower English letters only.
 * 2. Length of the given string and k will in the range [1, 10000]
 *
 Example:
 Input: s = "abcdefg", k = 2
 Output: "bacdfeg"
 **************************************************************************/

#include <string>
#include <algorithm>

using namespace std;

string reverseStrII(string s, int k)
{
	int i = 0, count = 0;
	while(i < s.length())
	{
		int j = min(i + k - 1, (int)s.length()-1);
		reverse(s.begin()+i, s.begin()+j+1);
		i += 2*k;
	}
	return s;
}




