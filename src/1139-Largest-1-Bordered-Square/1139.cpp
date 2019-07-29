class Solution 
{
public:
    int largest1BorderedSquare(vector<vector<int>>& grid) 
    {
        int r = grid.size(), c = grid[0].size();
        vector<vector<int>> h(r, vector<int> (c, 0)), v(r, vector<int>(c, 0));

        for (int i = 0; i < r; i++) 
        { 
            for (int j = 0; j < c; j++) 
            { 
                if (grid[i][j]) 
                { 
                    h[i][j] = (j == 0)? 1: h[i][j-1] + 1;  
                    v[i][j] = (i == 0)? 1: v[i-1][j] + 1;  
                } 
            } 
        } 
        
        int res = 0;
        for (int i = r - 1; i >= 0; i--) 
        { 
            for (int j = c - 1; j >= 0; j--) 
            { 
                int s = min(h[i][j], v[i][j]); 
                while (s > res) 
                { 
                    if (v[i][j - s + 1] >= s &&  h[i - s + 1][j] >= s) 
                    {
                        res = s; break;
                    } 
                    s--; 
                } 
            } 
        } 
        return res*res; 
    }
};