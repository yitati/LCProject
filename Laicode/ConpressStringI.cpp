/*
 * Laicode_ConpressStringI.cpp
 *

Given a string in compressed form, decompress it to the original string.
The adjacent repeated characters in the original string are compressed
to have the character followed by the number of repeated occurrences.
If the character does not have any adjacent repeated occurrences,
it is not compressed.

Assumptions

The string is not null

The characters used in the original string are guaranteed to be ‘a’ - ‘z’

There are no adjacent repeated characters with length > 9

Examples

“acb2c4” → “acbbcccc”

 */

#include <string>

using namespace std;

/*
 * since the size is expanding so we need to do this from back to front.
 * step 1. calculate how many spaces we need for the whole string.
 * step 2. parse the string from back to front.
 */

int getResize(string input)
{
	int count = 0, i = 0;
	while(i < input.length())
	{
		if(input[i] >= 'a' && input[i] <= 'z') count++;
		else count += input[i]-'0'-1;
		i++;
	}
	return count;
}


string decompress(string input)
{
	if(input.empty()) return input;
	int oldsize = input.size();
	int newsize = getResize(input);
	input.resize(newsize);
	int i = newsize-1, j = oldsize-1;
	while(j >= 0)
	{
		if(input[j] >= 'a' && input[j] <= 'z') input[i--] = input[j--];
		else{
			int count = input[j]-'0';
			char x = input[j-1];
			while(count > 0)
			{
				input[i--] = x;
				count--;
			}
			j = j-2;
		}
	}
	return input;
}


