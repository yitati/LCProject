/******************************************************************************/
/*
* Question: #320 Generalized Abbreviation
* Write a function to generate the generalized abbreviations of a word.
Example:
Given word = "word", return the following list (order does not matter):
["word", "1ord", "w1rd", "wo1d", "wor1", "2rd", "w2d", "wo2", "1o1d", "1or1", "w1r1", "1o2", "2r1", "3d", "w3", "4"]
*/
/*****************************************************************************/

#include <iostream>
#include <string>
#include <vector>

using namespace std;


void fillAbbreviations(vector<string> & results, string & curr, int index)
{
	results.push_back(curr);
	for (int i = index; i < curr.size(); i++)
	{
		char c = curr[i];
		curr[i] = '1';
		fillAbbreviations(results, curr, i + 1);
		curr[i] = c;
	}
}

vector<string> generateAbbreviations(string word)
{
	vector<string> results;
	fillAbbreviations(results, word, 0);
	return results;
}

/*
int main(int argc, char * argv[])
{
	string input = "word";
	vector<string> results = generateAbbreviations(input);
	for (int i = 0; i < results.size(); i++)
	{
		//cout << results[i] << endl;
	}
	cout << results.size() << endl;

	system("pause");
}
*/