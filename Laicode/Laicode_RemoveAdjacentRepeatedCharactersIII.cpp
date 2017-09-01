/*
 * Laicode_RemoveAdjacentRepeatedCharactersIII.cpp
 *
Remove adjacent, repeated characters in a given string, leaving no character for each group of such characters.
The characters in the string are sorted in ascending order.

Assumptions

Try to do it in place.
Examples

“aaaabbbc” is transferred to “c”
Corner Cases

If the given string is null, we do not need to do anything.
 */

#include <string>

using namespace std;

string deDup(string s)
{
	if(s.length() < 2) return s;
	int i=0, j=0;
	while(j < s.length())
	{
		int end = j;
		while(end+1 < s.length() && s[end+1] == s[end]) end++;
		if(end == j) s[i++] = s[j++];
		else j = end+1;
	}
	s.resize(i);
	return s;
}
