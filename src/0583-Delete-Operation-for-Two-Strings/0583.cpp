class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size(), n = word2.size();
        int l[m + 1][n + 1];
        memset(l, 0, sizeof l);
        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (word1[i-1] == word2[j-1]) 
                    l[i][j] = l[i-1][j-1] + 1;
                else l[i][j] = max(l[i-1][j], l[i][j-1]);
            }
        }
        return m + n - 2 * l[m][n];
    }
};