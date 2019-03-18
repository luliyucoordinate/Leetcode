static int x = []() {std::ios::sync_with_stdio(false); cin.tie(0); return 0; }();
class Solution 
{
public:
    int shipWithinDays(vector<int>& weights, int D) 
    {
        int r = accumulate(weights.begin(), weights.end(), 0);
        int l = max(r/D, *max_element(weights.begin(), weights.end()));
        while (l <= r) 
        {
            int m = (r - l)/2 + l;
            int need = 1, cur = 0;
            for (int w : weights)
            {
                if (cur + w > m)
                {
                    ++need, cur = 0;
                }
                cur += w;
            }
            if (need > D) l = m + 1;
            else r = m - 1;
        }
        return l;
    }
};