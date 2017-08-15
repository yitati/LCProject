/******************************************************************************/
/*
* Question: #52 N Queens II
* Follow up for N-Queens problem.
* Now, instead outputting board configurations, return the total number of distinct solutions.

*/
/*****************************************************************************/

#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

void fillNQueens(int n, int r, unordered_set<int>& column, unordered_set<int>& diag1, unordered_set<int>& diag2, int& count)
{
    if(r >= n)
    {
        count++;
        return;
    }

    for(int j=0; j<n; j++)
    {
        if(column.count(j)) continue;
        if(diag1.count(r+j)) continue;
        if(diag2.count(r-j)) continue;

        column.insert(j);
        diag1.insert(r+j);
        diag2.insert(r-j);
        fillNQueens(n, r+1, column, diag1, diag2, count);
        column.erase(j);
        diag1.erase(r+j);
        diag2.erase(r-j);
    }
}

int totalNQueens(int n)
{
    int count = 0;
    unordered_set<int> column;
    unordered_set<int> diag1;
    unordered_set<int> diag2;
    fillNQueens(n, 0, column, diag1, diag2, count);
    return count;
}
