class Solution 
{
public:
    int countNegatives(vector<vector<int>>& grid) 
    {
        int r = grid.size(), c = grid[0].size();
        int res = 0, m = r - 1, n = 0;
        
        while (m >= 0 && n < c)
        {
            if (grid[m][n] < 0)
            {
                res += c - n;
                m--;
            } else n++;
        }
        return res;
    }
};