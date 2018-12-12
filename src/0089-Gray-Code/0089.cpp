static int x = []() {std::ios::sync_with_stdio(false); cin.tie(0); return 0; }();
class Solution 
{
public:
    vector<int> grayCode(int n) 
    {
        if (n == 0) return {0};
        vector<int> res;
        for (int i = 0; i < 1<<n; ++i)
        {
            res.push_back(i^i>>1);
        }
        return res;
    }
};