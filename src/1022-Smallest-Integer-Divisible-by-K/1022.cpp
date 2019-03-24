static int x = []() {std::ios::sync_with_stdio(false); cin.tie(0); return 0; }();
class Solution 
{
public:
    int smallestRepunitDivByK(int K) 
    {
        if (K % 2 == 0 or K % 5 == 0) return -1;
        int res = 0;
        for (int i = 1; i <= K; ++i)
        {
            res = (res * 10 + 1) % K;
            if (res == 0) return i;
        }
        return -1;
    }
};