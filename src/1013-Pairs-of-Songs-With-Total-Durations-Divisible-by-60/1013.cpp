static int x = []() {std::ios::sync_with_stdio(false); cin.tie(0); return 0; }();
class Solution 
{
public:
    int numPairsDivisibleBy60(vector<int>& time) 
    {
        vector<int> cnt(60);
        int res = 0;
        for (int t : time) 
        {
            res += cnt[(60 - t%60)%60];
            cnt[t%60]++;
        }
        return res;
    }
};