class Solution 
{
public:
    int maximumMinimumPath(vector<vector<int>>& A) 
    {
        int r = A.size(), c = A[0].size();
        vector<vector<int>> vi(r, vector<int>(c, 0));
        priority_queue<vector<int>> q;
        q.push({A[0][0], 0, 0});
        while (!q.empty())
        {
            auto it = q.top(); q.pop();
            if (it[1] == r-1 and it[2] == c-1) return it[0];
            for (auto& d : dire)
            {
                int nx = d[0] + it[1], ny = d[1] + it[2];
                if (nx >= 0 and nx < r and ny >= 0 and ny < c
                    and vi[nx][ny] == 0)
                {
                    vi[nx][ny] = 1;
                    q.push({min(it[0], A[nx][ny]), nx, ny});
                }
            }
        }
        return 0;
    }
private:
    int dire[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
};