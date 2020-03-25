class Solution {
public:
    string longestPrefix(string s) {
        int n = s.size(), i = 0, j;
        int f[n + 1];
        memset(f, 0, sizeof f);
        f[0] = j = -1;
        
        while (i < n) {
            while (j != -1 && s[i] != s[j]) j = f[j];
            f[++i] = ++j;
        }
        return s.substr(0, f[n]);
    }
};