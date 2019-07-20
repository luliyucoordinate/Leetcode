class Solution 
{
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) 
    {
        if (grid.empty()) return -1;
        int r = grid.size(), c = grid[0].size();
        
        if (grid[0][0] == 1 or grid[r-1][c-1] == 1) return -1;
        deque<vector<int>> q;
        q.push_back({0, 0, 1});
        while (q.size())
        {
            auto pre = q.front();
            q.pop_front();
            if (pre[0] == r-1 and pre[1] == c-1) return pre[2];
            for (int i = 0; i < 8; ++i) {
                int nx = pre[0] + dire[i][0];
                int ny = pre[1] + dire[i][1];
                if (nx >= 0 and nx < r and ny >= 0 and ny < c and grid[nx][ny] == 0 ) 
                {
                    q.push_back({nx, ny, pre[2]+1});
                    grid[nx][ny] = 1;
                }
            }
        }
        return -1;
    }
private:
    int dire[8][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
};