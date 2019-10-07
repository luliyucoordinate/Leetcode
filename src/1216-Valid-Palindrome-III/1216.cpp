class Solution 
{
public:
    bool isValidPalindrome(string s, int k) 
    {
        string s2(s.rbegin(), s.rend());
        return s.size() - lcs(s, s2) <= k;
    }
    
    int lcs(string s1, string s2)
    {
        int n = s1.size();
        int l[n+1][n+1];
        memset(l, 0, sizeof l);
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (s1[i-1] == s2[j - 1]) 
                    l[i][j] = l[i-1][j-1] + 1;
                else l[i][j] = max(l[i][j-1], l[i-1][j]);
            }
        }
        return l[n][n];
    }
};