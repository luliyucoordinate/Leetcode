#include <cmath>
using namespace std;

static int x = []() {std::ios::sync_with_stdio(false); cin.tie(0); return 0; }();
class Solution 
{
public:
    int rangeBitwiseAnd(int m, int n) 
    {
        if (m == n) return m;
        int index = (int)log2(m ^ n) + 1;
        return m >> index << index; 
    }
};
