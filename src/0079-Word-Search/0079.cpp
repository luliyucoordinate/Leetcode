#include <iostream>
#include <string>
#include <vector>
using namespace std;

static int x = []() {std::ios::sync_with_stdio(false); cin.tie(0); return 0; }();
class Solution 
{
public:
    bool exist(vector<vector<char>>& board, const string& word) 
    {
        if (word.empty()) return true;
        
        m = board.size();
        n = board[0].size();
        if (word.size() > m * n) return false;
        
        const char* s = word.c_str();
        for (int i = 0; i < m; i++) 
            for (int j = 0; j < n; j++) 
                if (_exist(board, s, i, j)) return true;

        return false;
    }
private:
    int m, n;
    bool _exist(vector<vector<char>>& board, const char* s, int i, int j) 
    {
        if (board[i][j] != *s) return false;       
        
        board[i][j] = 0;
        if (*++s == 0) return true;
        if (i > 0 && _exist(board, s, i - 1, j)) return true;
        if (i < m - 1 && _exist(board, s, i + 1, j)) return true;            
        if (j > 0 && _exist(board, s, i, j - 1)) return true;
        if (j < n - 1 && _exist(board, s, i, j + 1)) return true;
        board[i][j] = *--s;
        return false;
    }
};