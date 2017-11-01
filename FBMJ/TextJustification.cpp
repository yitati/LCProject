/******************************************************************************
* Question: #68 Text Justification
* company tag: Facebook, LinkedIn
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
* Follow-up:
* company tag: Facebook
* What if we need to add page number and total number of pages at each end of line?
*****************************************************************************/

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

// a consice solution 
vector<string> textJustification(vector<string>& words, int maxWidth)
{
	vector<string> result;
	// i is word index
	for (int i = 0, wordNum = 0, lineLen = 0; i < words.size(); i += wordNum)
	{
		// first we need to calculate how many words in currently line
		// wordNum = number of words added to this line, and num of spaces added == wordNum - 1 
		// lineLen = length of line without space
		for (int wordNum = 0, lineLen = 0; i + wordNum < words.size() && lineLen + words[i + wordNum].size() + wordNum < maxWidth; wordNum++)
		{
			lineLen += words[i + wordNum].length();
			wordNum++;
		}
		string line = words[i];
		int evenlyDistributedSpace = (maxWidth - lineLen) / (wordNum - 1);
		int extraSpace = (maxWidth - lineLen) % (wordNum - 1);
		// there will be wordNum-1 slots to fill with spaces, j is space index
		for (int j = 0; j < wordNum - 1; j++)
		{
			// if this is the last line of word, should be left justified
			if (i + wordNum >= words.size()) line += " ";
			else
			{
				// first add evenly distributed Space
				line.append(evenlyDistributedSpace, ' ');
				// add one if it's "left"
				if (j < extraSpace)
				{
					line.append(1, ' ');
				}
			}
			line += words[i + j + 1];
		}
		// incase this is the last line
		line.append(maxWidth - line.size(), ' ');
		result.push_back(line);
	}
	return result;
}
