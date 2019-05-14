static int x = []() {std::ios::sync_with_stdio(false); cin.tie(0); return 0; }();
class Solution 
{
public:
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int r0, int c0, int color) 
    {
        r = grid.size(), c = grid[0].size();
        solve(grid, r0, c0, grid[r0][c0]);
        for (int i = 0; i < r; ++i) 
        {
            for (int j = 0; j < c; ++j) 
            {
                if (grid[i][j] < 0) grid[i][j] = color;
            }
        }
        return grid;
    }
private:
    vector<vector<int>> direct = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    int r, c;
    void solve(vector<vector<int>>& grid, int x, int y, int color) 
    {
        if (x < 0 or x >= r or y < 0 or y >= c or grid[x][y] != color) return;
        grid[x][y] = -color;
        for (auto& d : direct) 
        {
            int i = d[0] + x;
            int j = d[1] + y;
            solve(grid, i, j, color);
        }
        if (x > 0 and x < r-1 and y > 0 and y < c-1 and 
           abs(grid[x-1][y]) == color and abs(grid[x+1][y]) == color and
            abs(grid[x][y-1]) == color and abs(grid[x][y+1]) == color)
                grid[x][y] = color;
    }
};