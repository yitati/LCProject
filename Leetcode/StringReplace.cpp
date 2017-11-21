/*
Given an original string input, and two strings S and T, replace all occurrences of S in input with T.

Assumptions

input, S and T are not null, S is not empty string
Examples

input = "appledogapple", S = "apple", T = "cat", input becomes "catdogcat"
input = "dodododo", S = "dod", T = "a", input becomes "aoao"
*/

#include <string>
#include <vector>
#include <iostream>

using namespace std;

// s1 is the original pattern - to be updated
// s2 is the udpated pattern

// when s1.size() > s2.size()
string replaceshort(string & input, const string & s1, const string & s2)
{
	int s = 0;
	int f = 0;
	while (f < input.size())
	{
		int j = 0;
		// first we need to use strstr to find the s1 pattern
		while (j < s1.size() && f + s2.size() <= input.size() && s1[j] == input[f+j])
		{
			j++;
		}
		if (j == s1.size()) // we found a match (strstr)
		{
			for (int i = 0; i < s2.size(); i++)
			{
				input[s++] = s2[i];
			}
			f += s1.size();
		}
		else // this is not a match
		{
			input[s++] = input[f++];
		}
	}
	// not inlcuding slow pointer, the left should be the result to return
	input.resize(s);

	return input;
}

// when consider both s2.length() > s1.length() and s2.length() <= s1.length()
// fast always change length of S !!!!
// slow always change length of T !!!!
vector<int> getNeedleIndex(const string & haystack, const string & needle)
{
	cout << "inside sub" << endl;
	if (haystack.length() < needle.length()) return{};
	vector<int> needleIndex;
	for (int i = 0; i + needle.length() <= haystack.length(); i++)
	{
		int j = 0;
		while (j<needle.length() && haystack[i + j] == needle[j])
		{
			j++;
		}
		// we found a match
		if (j == needle.length())
		{
			needleIndex.push_back(i);
			i += j - 1;
		}
	}
	return needleIndex;
}


string replace(string input, string s, string t)
{
	// first we need to find how many match
	// and allocate more space for the input string
	vector<int> match;
	int slow = 0, fast = 0;
	match = getNeedleIndex(input, s);
	// if there is no match
	if (match.empty()) return input;
	int matches = match.size();
	int extraspace = matches * (t.length() - s.length());
	if (extraspace > 0) // when t has larger size
	{
		cout << "larger t" << endl;
		fast = input.size() - 1;
		input.resize(input.length() + extraspace);
		slow = input.size() - 1;
		while (fast >= 0)
		{
			// when we meet a match point
			if (!match.empty() && fast == (match.back() + s.length() - 1))
			{
				match.pop_back();
				for (int j = t.length() - 1; j >= 0; j--)
				{
					input[slow--] = t[j];
				}
				fast -= s.length();
			}
			else
			{
				input[slow--] = input[fast--];
			}
		}
	}
	else // when t has less length, copy from begin to end
	{
		cout << "smaller t" << endl;
		fast = slow = 0;
		int i = 0;
		while (fast < input.size())
		{
			if (i < match.size() && fast == match[i])
			{
				for (int j = 0; j < t.length(); j++)
				{
					input[slow++] = t[j];
				}
				fast += s.length();
				i++;
			}
			else
			{
				input[slow++] = input[fast++];
			}
		}
		input.resize(slow);
	}
	return input;
}

/*
int main(int argc, char * argv[])
{
	string input = "appledogapplethisapplebeeisnotappleb";
	string s = "apple";
	string t = "bigapple";

	input = replace(input, s, t);

	cout << input << endl;

	system("pause");
}
*/