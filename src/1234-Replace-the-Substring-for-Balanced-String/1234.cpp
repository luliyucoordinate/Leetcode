class Solution 
{
public:
    int balancedString(string s) 
    {
        unordered_map<int, int> cnt;
        for (auto c : s) cnt[c]++;
        int n = s.size(), res = n;
        int i = 0, avg = n / 4;
        for (int j = 0; j < n; j++)
        {
            cnt[s[j]]--;
            while (i < n && cnt['Q'] <= avg && 
                   cnt['W'] <= avg && 
                   cnt['E'] <= avg && 
                   cnt['R'] <= avg)
            {
                res = min(res, j - i + 1);
                cnt[s[i++]]++;
            }
        }
        return res;
    }
};