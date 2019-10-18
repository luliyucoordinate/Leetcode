class Solution 
{
public:
    int preimageSizeFZF(int K) 
    {
        int last = 1;
        while (last < K) last = last * 5 + 1;
        while (last > 1) 
        {
            K %= last;
            if (last - 1 == K) return 0;
            last = (last - 1) / 5;
        }
        return 5;
    }
};