/******************************************************************************
* Question: #37 Soduku Solver
* company tag: Salseforce
* Write a program to solve a Sudoku puzzle by filling the empty cells.
* Empty cells are indicated by the character '.'.
* You may assume that there will be only one unique solution.
*****************************************************************************/

#include <vector>

using namespace std;

vector<short> row;
vector<short> col;
vector<short> sub;

// dfs backtracking - plant one number at each spot and check if is valid, if not try another
bool sudokuSolver(vector<vector<char>>& board, int pos)
{
    int n = board.size();
    if(pos >= n*n) return true;
    int i = pos/n, j = pos%n;
    if(board[i][j] != '.') return sudokuSolver(board, pos+1);
    int k = (i / 3) * 3 + j / 3;
    for(char c = '1'; c <= '9'; c++)
    {
    	int mask = 1 << (c-'1');
    	if((row[i] & mask) || (col[j] & mask) || (sub[k] & mask)) continue;
    	row[i] |= mask;
    	col[j] |= mask;
    	sub[k] |= mask;
    	board[i][j] = c;
    	if(sudokuSolver(board, pos+1)) return true;
    	else // back tracking
    	{
    		row[i] &= ~mask;
    		col[j] &= ~mask;
    		sub[k] &= ~mask;
    		board[i][j] = '.';
    	}
    }
    return false;
}

// dfs back tracking - we can flatten the matrix index to simply the problem
void solveSudoku(vector<vector<char>>& board)
{
    row = vector<short>(9, 0);
    col = vector<short>(9, 0);
    sub = vector<short>(9, 0);
    // first we need to mark the existing row, col and sub
    for(int i=0; i<board.size(); i++)
    {
        for(int j=0; j<board[0].size(); j++)
        {
            if(board[i][j] == '.') continue;
            int k = (i/3)*3 + j/3, mask = 1 << (board[i][j]-'1');
            row[i] |= mask;
            col[j] |= mask;
            sub[k] |= mask;
        }
    }
    // then call the dfs and backtracking funtion
    sudokuSolver(board, 0);
}






