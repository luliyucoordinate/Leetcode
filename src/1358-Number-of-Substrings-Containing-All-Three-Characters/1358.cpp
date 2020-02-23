class Solution 
{
public:
    int numberOfSubstrings(string s) 
    {
        int cnt[3] = {0, 0, 0},res = 0 , l = 0, n = s.length();
        for (int r = 0; r < n; ++r)
        {
            ++cnt[s[r] - 'a'];
            while (cnt[0] && cnt[1] && cnt[2])
            {
                res += n - r;
                cnt[s[l++] - 'a']--;
            }
        }
        return res;
    }
};