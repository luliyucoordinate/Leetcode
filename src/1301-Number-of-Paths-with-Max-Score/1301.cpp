class Solution 
{
public:
    vector<int> pathsWithMaxScore(vector<string>& b) 
    {
        int n = b.size(), mod = 1e9 + 7;
        int d[3][2] = {{0, 1}, {1, 0}, {1, 1}};
        int dp[n][n][2] = {};
        dp[n-1][n-1][1] = 1;
        
        for (int x = n - 1; x >= 0; x--)
        {
            for (int y = n - 1; y >= 0; y--)
            {
                if (b[x][y] == 'X' || b[x][y] == 'S') continue;
                for (auto& it : d)
                {
                    if (dp[x][y][0] < dp[x + it[0]][y + it[1]][0])
                        dp[x][y][0] = dp[x + it[0]][y + it[1]][0], dp[x][y][1] = 0;
                    if (dp[x][y][0] == dp[x + it[0]][y + it[1]][0])
                        dp[x][y][1] = (dp[x][y][1] + dp[x + it[0]][y + it[1]][1]) % mod;
                }
                dp[x][y][0] += x || y ? b[x][y] - '0' : 0;
            }
        }
        return {dp[0][0][1] ? dp[0][0][0] : 0, dp[0][0][1]};
    }
};