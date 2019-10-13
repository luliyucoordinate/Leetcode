class Solution 
{
public:
    vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) 
    {
        int g[8][8];
        memset(g, 0, sizeof g);
        vector<vector<int>> res;
        for (auto& it : queens) g[it[0]][it[1]] = 1;
        for (int i = -1; i <= 1; i++)
        {
            for (int j = -1; j <= 1; j++)
            {
                for (int k = 1; k < 8; k++)
                {
                    int x = king[0] + k*i, y = king[1] + k*j;
                    if (x >= 0 and y >= 0 and 
                        x < 8 and y < 8 and g[x][y] == 1) 
                    {
                        res.push_back({x, y});
                        break;
                    }
                }
            }
        }
        return res;
    }
};