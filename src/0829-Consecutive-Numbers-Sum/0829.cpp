class Solution 
{
public:
    int consecutiveNumbersSum(int n) 
    {
        int res = 0;
        for (int i = 1; i*(i- 1) < 2 * n; ++i) {
            if (2*n % i == 0 and (2*n/i - i + 1) % 2 == 0) ++res;
        }
        return res;
    }
};