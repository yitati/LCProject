/*
 * Laicode_EncodeSpace.cpp
 *

In URL encoding, whenever we see an space " ", we need to replace it with "20%".
Provide a method that performs this encoding for a given string.

Examples

"google/q?flo wer market" → "google/q?flo20%wer20%market"
Corner Cases

If the given string is null, we do not need to do anything.

 */

#include <string>

using namespace std;

int getSpaceCount(string s)
{
	int count = 0;
	for(char c : s)
	{
		if(c == ' ') count++;
	}
	return count;
}

/*
 * in-place replace the string for space
 */
string encode(string s)
{
	if(s.empty()) return s;
	int spaceCount = getSpaceCount(s);
	/*
	 * every space takes 20% which is 3 char, it originally took one char, so we need 2 more
	 * char for each of the space
	 */
	int oldSize = s.length();
	int newSize = oldSize + 2 * spaceCount;
	s.resize(newSize);
	/*
	 * redo the string from back to front
	 */
	int i = oldSize-1;
	int j = newSize-1;
	while(i>=0)
	{
		if(s[i] == ' ')
		{
			s[j--] = '%';
			s[j--] = '0';
			s[j--] = '2';
		}
		else
		{
			s[j--] = s[i];
		}
		i--;
	}
	return s;
}
