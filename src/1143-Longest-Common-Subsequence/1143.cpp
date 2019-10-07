class Solution 
{
public:
    int longestCommonSubsequence(string text1, string text2) 
    {
        int m = text1.size(), n = text2.size();
        int l[m + 1][n + 1];
        memset(l, 0, sizeof l);
        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (text1[i-1] == text2[j-1]) 
                    l[i][j] = l[i-1][j-1] + 1;
                else l[i][j] = max(l[i-1][j], l[i][j-1]);
            }
        }
        return l[m][n];
    }
};