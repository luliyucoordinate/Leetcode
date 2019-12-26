class Solution 
{
public:
    int characterReplacement(string s, int k) 
    {
        int res = 0, n = s.size(), l = 0, mf = 0;
        unordered_map<char, int> d;
        for (int r = 0; r < n; ++r)
        {
            mf = max(mf, ++d[s[r]]);
            while (r - l + 1 - mf > k)
            {
                d[s[l]]--; l++;
            }
            res = max(res, r - l + 1);
        }
        return res;
    }
};