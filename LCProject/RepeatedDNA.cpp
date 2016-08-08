/******************************************************************************/
/**
* Question: #187 Repeated DNA Sequences
* All DNA is composed of a series of nucleotides abbreviated as A, C, G, and T, for example:
* "ACGAATTCCG". When studying DNA, it is sometimes useful to identify repeated sequences within
* the DNA.
* Write a function to find all the 10-letter-long sequences (substrings) that occur more than once in a DNA molecule.
*
* For example,
* Given s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT",
* Return: ["AAAAACCCCC", "CCCCCAAAAA"].
*
/*****************************************************************************/

#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <set>

using namespace std;

class RepeatedDNA {
public:
	vector<string> findRepeatedDnaSequences(string s) {
		vector<string> result;
		unordered_set<string> visited;
		if (s.size() < 10) return result;
		string curr;
		for (int index = 0; index+9 < s.size(); index++) 
		{
			curr = s.substr(index, 10);
			// find one sub string appears twice
			if (s.find(curr, index + 1) != std::string::npos)
			{
				if (visited.find(curr) == visited.end())
				{
					result.push_back(curr);
					visited.insert(curr);
				}
			}
		}
		return result;
	}


	vector<string> findRepeatedDnaSequences_BM(string s) {
		unordered_set<int> words;
		vector<string> result;
		char map[26];
		map['A' - 'A'] = 0;
		map['C' - 'A'] = 1;
		map['G' - 'A'] = 2;
		map['T' - 'A'] = 3;

		for (int i = 0; i < s.length() - 9; i++) {
			int v = 0;
			for (int j = i; j < i + 10; j++) {
				v <<= 2;
				v |= map[s[j] - 'A'];
			}
			if (words.find(v) != words.end())
			{
				result.push_back(s.substr(i, 10));
			}
			else {
				words.insert(v);
			}
		}
		return result;
	}
};

/*
int main(int argc, char * argv)
{
	string s1 = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT";
	string s2 = "AAAAAAAAAA";
	string s3 = "AAAAAAAAAAA";

	RepeatedDNA repeatDNA;

	vector<string> result1 = repeatDNA.findRepeatedDnaSequences_BM(s1);

	for (int i = 0; i < result1.size(); i++)
	{
		cout << result1[i] << endl;
	}

	vector<string> result2 = repeatDNA.findRepeatedDnaSequences_BM(s2);

	for (int i = 0; i < result2.size(); i++)
	{
		cout << result2[i] << endl;
	}

	vector<string> result3 = repeatDNA.findRepeatedDnaSequences_BM(s3);

	for (int i = 0; i < result3.size(); i++)
	{
		cout << result3[i] << endl;
	}

	system("pause");
}
*/