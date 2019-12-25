class Solution 
{
public:
    int maxFreq(string s, int maxLetters, int minSize, int maxSize) 
    {
        char chs[256] = {};
        int nq = 0, res = 0, l = minSize;
        unordered_map<string, int> cnt;
        
        for (int r = 0; r < s.size(); r++)
        {
            if (chs[s[r]]++ == 0) ++nq;
            if (l <= r)
            {
                if (--chs[s[r - l]] == 0) --nq;
            }
            
            if (l - 1 <= r && nq <= maxLetters)
            {
                res = max(res, ++cnt[s.substr(r - l + 1, l)]);
            }
        }
        return res;
    }
};