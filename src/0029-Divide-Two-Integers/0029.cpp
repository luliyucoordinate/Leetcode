#include <cstdlib>
using namespace std;

static int x = [](){std::ios::sync_with_stdio(false);cin.tie(0);return 0;}();
class Solution 
{
public:
    int divide(int dividend, int divisor) 
    {
        long long res = 0;
        long long divd = labs(dividend), divs = labs(divisor);
        int pos = (dividend < 0) ^ (divisor < 0);
        long long mod = (long long)INT_MAX + 1;
        if (divd < divs) return 0;
        while (divs <= divd)
        {
            long long mul = 1, tmp = divs;
            while ((tmp << 1) <= divd)
            {
                mul <<= 1; tmp <<= 1;
            }
            res += mul; divd -= tmp;
            if (res == mod) break;
        }
        if (pos == 0 and res == mod) res -= 1;
        return pos == 0 ? res : -res;
    }
};