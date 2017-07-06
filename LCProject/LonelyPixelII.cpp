/*******************************************************************************
 * Question #533 Lonely Pixel II
 * Given a picture consisting of black and white pixels, and a positive integer N, find the number of black
 * pixels located at some specific row R and column C that align with all the following rules:
 * 1. Row R and column C both contain exactly N black pixels.
 * 2. For all rows that have a black pixel at column C, they should be exactly the same as row R.
 * The picture is represented by a 2D char array consisting of 'B' and 'W', which means black and
 * white pixels respectively.

 Exmaple:

Input:
[['W', 'B', 'W', 'B', 'B', 'W'],
 ['W', 'B', 'W', 'B', 'B', 'W'],
 ['W', 'B', 'W', 'B', 'B', 'W'],
 ['W', 'W', 'B', 'W', 'B', 'W']]

N = 3
Output: 6
Explanation: All the bold 'B' are the black pixels we need (all 'B's at column 1 and 3).
        0    1    2    3    4    5         column index
0    [['W', 'Bb', 'W', 'Bb', 'B', 'W'],
1     ['W', 'Bb', 'W', 'Bb', 'B', 'W'],
2     ['W', 'Bb', 'W', 'Bb', 'B', 'W'],
3     ['W', 'W' , 'B', 'W' , 'B', 'W']]
row index

Take 'B' at row R = 0 and column C = 1 as an example:
Rule 1, row R = 0 and column C = 1 both have exactly N = 3 black pixels.
Rule 2, the rows have black pixel at column C = 1 are row 0, row 1 and row 2.
They are exactly the same as row R = 0.

 * Note:
 * 1. The range of width and height of the input 2D array is [1, 200].

 *********************************************************************************/

#include <vector>
#include <unordered_set>

using namespace std;

// use "signature" which is a string to represent each row, and count how many times the signature appears
// like in above example we get "WBWBBW": 3, "WWBWBW": 1
// then "WBWBBW" is our candidate, then we search each of its col to check if count == N
string getRowString(vector<vector<char>>& picture, int N, int i, vector<int>& countc)
{
	string result;
	int rowCount = 0;
	for(int j=0; j<picture[i].size(); j++)
	{
		if(picture[i][j] == 'B')
		{
			rowCount++;
			countc[j]++;
		}
		result.push_back(picture[i][j]);
	}
	if(rowCount != N) return "";
	return result;
}

int findBlackPixel(vector<vector<char>>& picture, int N)
{
	if(picture.empty() || picture[0].empty()) return {};
	int row = picture.size(), col = picture[0].size(), count = 0;
	unordered_map<string, int> recordr;
	vector<int> countc(col, 0);

	for(int i=0; i<row; i++)
	{
		// update row sig and col counter at the same time
		string sig = getRowString(picture, N, i, countc);
		if(!sig.empty())
		{
			recordr[sig]++;
		}
	}

	for(auto& it : recordr)
	{
        if(it.second != N) continue;
		for(int j=0; j<col; j++)
		{
			if(it.first[j] == 'B' && countc[j] == N) count += N;
		}
	}

	return count;
}



