class Solution 
{
public:
    int uniqueLetterString(string S) 
    {
        int res = 0, f = 0, mod = 1e9 + 7;
        int m[26] = {}, n[26] = {};
        for (int i = 0; i < S.size(); i++)
        {
            int t = S[i] - 'A';
            f = f + 1 + i - 2 * m[t] + n[t];
            res = (res + f) % mod;
            n[t] = m[t];
            m[t] = i + 1;
        }
        return res;
    }
};