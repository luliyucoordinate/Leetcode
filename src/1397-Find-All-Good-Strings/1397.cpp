const int N = 501, M = 51;
class Solution {
public:
    int findGoodStrings(int n, string &s1, string &s2, string &evil) {
        ne[0] = -1;
        for (int i = 0, j = -1; i < evil.size();) {
            while (j != -1 && evil[i] != evil[j]) j = ne[j];
            ne[++i] = ++j;
        }
        return dfs(s1, s2, evil, 0, 0, true, true);
    }
private:
    int dp[N][M][2][2] = {};
    int ne[M] = {};
    
    int dfs(string &s1, string &s2, string &evil, int si, int ei, bool lt, bool rt) {
        if (ei == evil.size()) return 0;
        if (si == s1.size()) return 1;
        if (dp[si][ei][lt][rt]) return dp[si][ei][lt][rt];
        
        auto l = lt ? s1[si] : 'a';
        auto r = rt ? s2[si] : 'z';
        
        for (char i = l; i <= r; i++) {
            auto t = ei;
            while (t != -1 && evil[t] != i) t = ne[t];
            dp[si][ei][lt][rt] = (dp[si][ei][lt][rt] + 
                                dfs(s1, s2, evil, si + 1, t + 1, lt && (i == l), rt && (i == r))) % 1000000007;
        }
        return dp[si][ei][lt][rt];
    }
};