/******************************************************************************
* Question: #79 Word Search
* company tag: Facebook
* Given a 2D board and a word, find if the word exists in the grid.

* The word can be constructed from letters of sequentially adjacent cell, 
* where "adjacent" cells are those horizontally or vertically neighboring. 
* The same letter cell may not be used more than once.

For example,
Given board =

[
['A','B','C','E'],
['S','F','C','S'],
['A','D','E','E']
]
word = "ABCCED", -> returns true,
word = "SEE", -> returns true,
word = "ABCB", -> returns false.

*****************************************************************************/

#include <vector>
#include <string>

using namespace std;

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

bool isWordExists(const vector<vector<char>>& board, vector<vector<bool>>& visit, string word, int pos, int r, int c)
{
    if(pos >= word.length())
    {
        return true;
    }

    for(int k=0; k<4; k++)
    {
        int x = r + dx[k];
        int y = c + dy[k];
        if(x < 0 || x >= board.size() || y < 0 || y >= board[0].size() || visit[x][y] || board[x][y] != word[pos]) continue;
        visit[x][y] = true;
        if(isWordExists(board, visit, word, pos+1, x, y)) return true;
        visit[x][y] = false;
    }

    return false;
}

bool exist(vector<vector<char>>& board, string word)
{
    if(board.empty() || board[0].empty() || word.empty()) return false;
    // since same cell cannot be used twice so we need to mark visited
    vector<vector<bool>> visit(board.size(), vector<bool>(board[0].size(), false));
    for(int i=0; i<board.size(); i++)
    {
        for(int j=0; j<board[0].size(); j++)
        {
            if(board[i][j] == word[0])
            {
                visit[i][j] = true;
                if(isWordExists(board, visit, word, 1, i, j)) return true;
                visit[i][j] = false;
            }
        }
    }
    return false;
}
