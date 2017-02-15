/******************************************************************************/
/*
* Question: #6 ZigZag Conversion
* The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: 
* (you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R

* And then read line by line: "PAHNAPLSIIGYIR"
* Write the code that will take a string and make this conversion given a number of rows:

* string convert(string text, int nRows);
* convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".
*/
/*****************************************************************************/

#include <string>
#include <vector>
#include <iostream>

using namespace std;


// create a string vector to store the converted string rows
string convert(string s, int numRows)
{
	if (numRows == 0 || numRows == 1) return s;
	int len = s.length(), i = 0;
	vector<string> table(numRows);
	string result;
	while (i < len)
	{
		// fill the row from top to bottom
		for (int k = 0; k < numRows && i < len; k++)
		{
			table[k].push_back(s[i++]);
		}
		// fill the row zig zag up
		for (int k = numRows - 2; k > 0 && i < len; k--)
		{
			table[k].push_back(s[i++]);
		}
	}

	for (int k = 0; k < numRows; k++)
	{
		result.append(table[k]);
	}

	return result;
}
