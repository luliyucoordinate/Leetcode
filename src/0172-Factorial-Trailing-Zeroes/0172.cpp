static int x = []() {std::ios::sync_with_stdio(false); cin.tie(0); return 0; }();
class Solution 
{
public:
    int trailingZeroes(int n) 
    {
        int res = 0;
        while (n) res += (n /= 5);
        return res;
    }
};