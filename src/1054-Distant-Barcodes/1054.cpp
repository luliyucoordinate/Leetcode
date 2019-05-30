static int x = []() {std::ios::sync_with_stdio(false); cin.tie(0); return 0; }();
class Solution 
{
public:
    vector<int> rearrangeBarcodes(vector<int>& b) 
    {
        short m[10001] = {};
        short max_cnt = 0, max_n = 0, pos = 0;
        for (int n : b) 
        {
            if (max_cnt < ++m[n]) 
            {
                max_cnt = m[n];
                max_n = n;
            }
        }
        for (int i = 0; i <= 10000; ++i) 
        {
            int n = i == 0 ? max_n : i;
            while (m[n]-- > 0) 
            {
                b[pos] = n;
                pos = pos + 2 < b.size() ? pos + 2 : 1;
            }
        }
        return b;
    }
};