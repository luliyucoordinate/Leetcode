#include <bitset>
using namespace std;

static int x = []() {std::ios::sync_with_stdio(false); cin.tie(0); return 0; }();
class Solution 
{
public:
    int hammingWeight(uint32_t n) 
    {
        bitset<32> bin(n);
        return bin.count();
    }
};