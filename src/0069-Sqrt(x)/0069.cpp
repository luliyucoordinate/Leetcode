static int x = []() {std::ios::sync_with_stdio(false); cin.tie(0); return 0; }();
class Solution 
{
public:
    int mySqrt(int x) 
    {
        long res = x;
        while (res * res > x) 
        {
            res = (res + x / res) / 2;
        }
        return res;
    }
};