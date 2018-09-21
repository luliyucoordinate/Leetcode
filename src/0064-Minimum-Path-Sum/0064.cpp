#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

static int x = []() {std::ios::sync_with_stdio(false); cin.tie(0); return 0; }();
class Solution 
{
public:
    int minPathSum(vector<vector<int>>& grid) 
    {
        if(grid.empty()) return 0;
        int r = grid.size();
        int c = grid[0].size();
        vector<vector<int>> mem(r, vector<int>(c, 0));
        mem[0][0] = grid[0][0];
        for (unsigned int i = 1; i < c; ++i)
        {
            mem[0][i] = grid[0][i] + mem[0][i - 1];
        }
        for (unsigned int i = 1; i < r; ++i)
        {
            mem[i][0] = grid[i][0] + mem[i - 1][0];
        }
        for (unsigned int i = 1; i < r; ++i)
        {
            for (unsigned int j = 1; j < c; ++j)
            {
                mem[i][j] = grid[i][j] + min(mem[i - 1][j], mem[i][j - 1]);
            }
        }
        return mem[r - 1][c - 1];
    }
};