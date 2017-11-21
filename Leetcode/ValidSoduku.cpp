/******************************************************************************/
/*
* Question: #36 Valid Soduku
* Determine if a Sudoku is valid, according to: Sudoku Puzzles - The Rules.
* The Sudoku board could be partially filled, where empty cells are filled with the character '.'
* Note:
* A valid Sudoku board (partially filled) is not necessarily solvable. Only the filled cells need to be validated.
*/
/*****************************************************************************/

#include <vector>
#include <unordered_set>

using namespace std;

/*
 * Sudoku rules
 * 	1. Each row must have the numbers 1-9 occuring just once.
 * 	2. Each col must have the numbers 1-9 occuring just once.
 * 	3. Each 9 sub-boes must have the numbers 1-9 occuring just once.
 */

// hashset / bit manipulation 
// we have 9 numbers to check, and one int has 32 bit
bool isValidSudoku(vector<vector<char>>& board)
{
	int len = board.size();
	vector<short> row(len, 0);
	vector<short> col(len, 0);
	vector<short> block(len, 0);

	for (int i = 0; i < len; i++)
	{
		for (int j = 0; j < len; j++)
		{
			if (board[i][j] == '.') continue;
			int mask = 1 << (board[i][j] - '0' - 1);
			int k = i / 3 * 3 + j / 3;
			// if this number exist in current row / column / block
			if ((row[i] & mask) || (col[j] & mask) || (block[k] & mask)) return false;
			row[i] |= mask;
			col[j] |= mask;
			block[k] |= mask;
		}
	}

	return true;
}

