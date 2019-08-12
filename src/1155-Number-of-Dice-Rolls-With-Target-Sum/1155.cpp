class Solution 
{
public:
    int numRollsToTarget(int d, int f, int target) 
    {
        vector<int> mem(target + 1);
        mem[0] = 1;
        for (int i = 0; i < d; ++i)
        {
            vector<int> tmp(target + 1);
            for (int j = 1; j <= f; ++j)
            {
                for (int k = j; k <= target; ++k)
                {
                    tmp[k] = (tmp[k] + mem[k - j]) % 1000000007;
                }
            }
            swap(tmp, mem);
        }
        return mem.back();
    }
};