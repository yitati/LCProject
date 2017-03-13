/******************************************************************************/
/*
* Question: #68 Text Justification
* Given an array of words and a length L, format the text such that each line has exactly L characters and 
* is fully (left and right) justified. 
* You should pack your words in a greedy approach; that is, pack as many words as you can in each line. 
* Pad extra spaces ' ' when necessary so that each line has exactly L characters. 
* Extra spaces between words should be distributed as evenly as possible. 
* If the number of spaces on a line do not divide evenly between words, the empty slots on the left 
* will be assigned more spaces than the slots on the right. 

* For the last line of text, it should be left justified and no extra space is inserted between words. 

For example,
words: ["This", "is", "an", "example", "of", "text", "justification."]
L: 16. 

Return the formatted lines as:

[
   "This    is    an",
   "example  of text",
   "justification.  "
]

* Note: Each word is guaranteed not to exceed L in length. 
*/
/*****************************************************************************/

#include <vector>
#include <string>

using namespace std;

vector<string> fullJustify(vector<string>& words, int maxWidth) {
	vector<string> results;
	int start = 0, end = 0;
	while (end < words.size())
	{
		string result;
		int total = 0;
		while (end < words.size() && total + words[end].length() + (end - start) <= maxWidth)
		{
			total += words[end].length();
			end++;
		}
		end--;
		int interval = end - start;
		int avgSpace = 0, leftCount = 0;
		if (interval)
		{
			avgSpace = (maxWidth - total) / interval;
			leftCount = (maxWidth - total) % interval;
		}

		for (int i = start; i < end; i++)
		{
			result += words[i];
			if (i == end) break;
			if (end == words.size() - 1)
			{
				result.insert(result.end(), ' ');
			}
			else
			{
				result.append(avgSpace, ' ');
				if (leftCount)
				{
					result.append(1, ' ');
					leftCount--;
				}
			}

		}
		result += words[end];
		if (result.size() < maxWidth)
		{
			result.append(maxWidth - result.size(), ' ');
		}
		results.push_back(result);
		start = end + 1;
		end = start;
	}
	return results;
}