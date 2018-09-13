#include <iostream>
#include <string>
#include <vector>
using namespace std;

static int x = []() {std::ios::sync_with_stdio(false); cin.tie(0); return 0; }();
class Solution 
{
public:
    void solve(vector<vector<char>>& board) 
    {
        if (board.empty()) return;
        m = board.size(); n = board[0].size();
        for (unsigned int i = 0; i < m; ++i)
        {
            _solve(board, i, 0);
            _solve(board, i, n - 1);
        }
        for (unsigned int i = 0; i < n; ++i)
        {
            _solve(board, 0, i);
            _solve(board, m - 1, i);
        }

        for (unsigned int i = 0; i < m; ++i)
        {
            for (unsigned int j = 0; j < n; ++j)
            {
                if (board[i][j] == 'O') board[i][j] = 'X';
                else if (board[i][j] == '*') board[i][j] = 'O';
            }
        }
    }
private:
    unsigned int m , n;
    void _solve(vector<vector<char>>& board, unsigned int i, unsigned int j)
    {      
        if (board[i][j] != 'O') return;       
        board[i][j] = '*';
        if (i > 0) _solve(board, i - 1, j);
        if (i < m - 1) _solve(board, i + 1, j);            
        if (j > 0) _solve(board, i, j - 1);
        if (j < n - 1)_solve(board, i, j + 1);
    }
};