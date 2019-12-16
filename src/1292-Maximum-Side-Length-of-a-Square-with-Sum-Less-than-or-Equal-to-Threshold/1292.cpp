class Solution 
{
public:
    int maxSideLength(vector<vector<int>>& m, int t) 
    {
        int r = m.size(), c = m[0].size();
        int data[r+1][c+1] = {};
        for (int i = 1; i <= r; i++) 
        {
            for (int j = 1; j <=c; j++) 
            {
                data[i][j] = data[i-1][j] + data[i][j-1] - data[i-1][j-1] + m[i-1][j-1];
            }
        }
        
        int res = 0, l = 0;
        for (int i = 0; i <= r; i++)
        {
            for (int j = 0; j <= c; j++)
            {
                while (i + l <= r && j + l <= c && 
                      data[i+l][j+l] - data[i+l][j] - data[i][j+l] + data[i][j] <= t)
                {
                    res = l++;
                }
            }
        }
        return res;
    }
};