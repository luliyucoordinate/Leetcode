#include <iostream>
using namespace std;

static int x = []() {std::ios::sync_with_stdio(false); cin.tie(0); return 0; }();
const int I_MAX = 0x7fffffff/10;
const int I_MIN = (-0x7fffffff - 1)/10;
class Solution 
{
public:
    int reverse(int x) 
    {
        int r = 0;
        while (x) {
            if (r > I_MAX or r < I_MIN) return 0;
            int tail = x % 10;
            int newR = r * 10 + tail;
            if ((newR - tail) / 10 != r) return 0;
            r = newR, x /= 10;
        }
        return r;
    }
};