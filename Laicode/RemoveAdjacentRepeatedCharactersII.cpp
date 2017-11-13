/*
 * Laicode_RemoveAdjacentRepeatedCharactersII.cpp
 *
Remove adjacent, repeated characters in a given string, leaving only two characters for each group of such characters.
The characters in the string are sorted in ascending order.

Assumptions

Try to do it in place.
Examples

“aaaabbbc” is transferred to “aabbc”
Corner Cases

If the given string is null, we do not need to do anything.
 */

#include <string>

using namespace std;

string deDupII(string s)
{
	if(s.length() <= 2) return s;
	int j = 2;
	for(int i=j; i<s.length(); i++)
	{
		if(s[i] > s[j-2]) s[j++] = s[i];
	}
	// [0, j) is our result
	s.resize(j);
	return s;
}
