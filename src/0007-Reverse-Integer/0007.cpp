#include <iostream>
using namespace std;

static int x = []() {std::ios::sync_with_stdio(false); cin.tie(0); return 0; }();
class Solution 
{
public:
    int reverse(int x) 
    {
        long r = 0;
        while (x) r = r*10 + x%10, x /= 10;
        return (int(r) == r) * r;
    }
};