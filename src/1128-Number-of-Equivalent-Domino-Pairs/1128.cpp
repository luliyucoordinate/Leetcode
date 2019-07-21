class Solution 
{
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) 
    {
        unordered_map<int, int> cnt;
        int res = 0;
        for (auto& d : dominoes) 
        {
            res += cnt[min(d[0], d[1]) * 10 + max(d[0], d[1])]++;
        }
        return res;
    }
};