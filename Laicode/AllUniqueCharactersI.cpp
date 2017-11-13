/*
 * AllUniqueCharactersI.cpp
 *

Determine if the characters of a given string are all unique.

Assumptions

The only set of possible characters used in the string are 'a' - 'z', the 26 lower case letters.
The given string is not null.
Examples

the characters used in "abcd" are unique
the characters used in "aba" are not unique

 */

#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

bool allUnique(string s)
{
	int visit = 0;
	for(char c : s)
	{
		int mask = 1 << (c-'a');
		if((visit & mask) != 0) return false;
		visit |= mask;
	}
	return true;
}

