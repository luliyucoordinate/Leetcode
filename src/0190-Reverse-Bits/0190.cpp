static int x = []() {std::ios::sync_with_stdio(false); cin.tie(0); return 0; }();
class Solution 
{
public:
    uint32_t reverseBits(uint32_t n) 
    {
        uint32_t res = 0;
        for (int i = 0; i < 32; ++i)
        {
            res = (res << 1) + (n & 1);
            n >>= 1;
        }
        return res;
    }
};