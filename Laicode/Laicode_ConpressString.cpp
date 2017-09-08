/*
 * Laicode_ConpressString.cpp
 *

Given a string, replace adjacent, repeated characters with the character followed
by the number of repeated occurrences. If the character does not has any adjacent,
repeated occurrences, it is not changed.

Assumptions

The string is not null

The characters used in the original string are guaranteed to be ‘a’ - ‘z’

There are no adjacent repeated characters with length > 9

Examples

“abbcccdeee” → “ab2c3de3”

 */

#include <string>

using namespace std;

string compress(string input)
{
	if(input.empty()) return input;
	int slow = 0, fast = 0;
	while(fast < input.size())
	{
		int next = fast;
		while(next+1 < input.size() && input[next+1] == input[next]) next++;
		next++;
		int count = next-fast;
		input[slow++] = input[fast];
		if(count > 1)
		{
			input[slow++] = '0'+count;
		}
		fast = next;
	}
	input.resize(slow);
	return input;
}

