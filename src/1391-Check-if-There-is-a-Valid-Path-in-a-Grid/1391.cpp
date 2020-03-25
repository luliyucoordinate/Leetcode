class Solution {
public:
    bool hasValidPath(vector<vector<int>>& grid) {
        r = grid.size(), c = grid[0].size();
        return dfs(grid, 0, 0, 0) || dfs(grid, 0, 0, 1) || dfs(grid, 0, 0, 2) || dfs(grid, 0, 0, 3);
    }
private:
    int r, c;
    int d[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    int p[6][4] =  {{2, -1, 0, -1}, 
                    {-1, 3, -1, 1}, 
                    {-1, 2, 1, -1},
                    {1, 0, -1, -1},
                    {-1, -1, 3, 2},
                    {3, -1, -1, 0}};
    
    bool dfs(vector<vector<int>>& grid, int x, int y, int di) {
        if (p[grid[x][y] - 1][di] == -1) return false;
        if (x == r - 1 && y == c - 1) return true;
        
        int dx = d[p[grid[x][y] - 1][di]][0], dy = d[p[grid[x][y] - 1][di]][1];
        int nx = x + dx, ny = y + dy;
        if (0 <= nx && nx < r && 0 <= ny && ny < c) {
            if (dfs(grid, nx, ny, (p[grid[x][y] - 1][di] + 2) % 4)) return true;
        }
        return false;
    }
};