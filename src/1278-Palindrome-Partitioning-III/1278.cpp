class Solution 
{
public:
    int palindromePartition(string s, int k) 
    {
        int n = s.size();
        int p[n][n] = {}, f[k+1][n] = {};
        for (int j = 1; j < n; j++) 
        {
            for (int i = j - 1; i >= 0; i--)
            {
                p[i][j] = s[i] == s[j] ? 0 : 1;
                if (i + 1 < j) p[i][j] += p[i+1][j-1];
            }
        }
        
        memset(f, 0x3f, sizeof f);
        for (int i = 0; i < n; i++) f[1][i] = p[0][i];
        for (int i = 2; i <= k; i++)
        {
            for (int r = i - 1; r < n; r++)
            {
                for (int l = i - 2; l < r; l++) 
                {
                    f[i][r] = min(f[i][r], f[i-1][l] + p[l+1][r]);
                }
            }
        }
        return f[k][n-1];
    }
};