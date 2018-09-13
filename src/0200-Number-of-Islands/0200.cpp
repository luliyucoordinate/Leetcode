#include <iostream>
#include <string>
#include <vector>
using namespace std;

static int x = []() {std::ios::sync_with_stdio(false); cin.tie(0); return 0; }();
class Solution 
{
public:
    int numIslands(vector<vector<char>>& grid) 
    {
        if (grid.empty()) return 0;
        int result = 0;
        for (unsigned int i = 0; i < grid.size(); ++i)
        {
            for (unsigned int j = 0; j < grid[0].size(); ++j)
            {
                if (grid[i][j] == '1')
                {
                    result++;
                    _numIslands(grid, i, j);
                }
            }
        }
        return result;
    }
private:
    void _numIslands(vector<vector<char>>& grid, unsigned int r, unsigned int c) 
    {
        grid[r][c] = '0';
        if (0 < r and grid[r - 1][c] == '1') _numIslands(grid, r - 1, c);
        if (0 < c and grid[r][c - 1] == '1') _numIslands(grid, r, c - 1);
        if (c < grid[0].size() - 1 and grid[r][c + 1] == '1') _numIslands(grid, r, c + 1);
        if (r < grid.size() - 1 and grid[r + 1][c] == '1') _numIslands(grid, r + 1, c);
    }
};