class Solution 
{
public:
    int maxRepOpt1(string s) 
    {
        int res = 0, n = s.size(), l = 0, mf = 0;
        char mc = s[0];
        
        unordered_map<char, int> d, cnt;
        for (char c : s) cnt[c]++;
        
        for (int r = 0; r < n; ++r)
        {
            if (mf < ++d[s[r]])
            {
                mf = d[s[r]];
                mc = s[r];
            }

            if (r - l + 1 - mf > 1)
            {
                d[s[l]]--; l++;
            }
            res = max(res, r - l + 1);
        }
        return min(res, cnt[mc]);
    }
};