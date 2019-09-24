class Solution 
{
public:
    int nthUglyNumber(int n, int a, int b, int c) 
    {
        long long l = 1, r = 2000000000;
        while (l < r)
        {
            long long mid = (l + r) >> 1;
            if (cnt(mid, a, b, c) < n) l = mid + 1;
            else r = mid;
        }
        return l;
    }
    
    long long lcm2(int x, int y)
    {
        return x*1ll*y/__gcd(x, y);
    }
    
    long long lcm3(int x, int y, int z)
    {
        long long res = x*1ll*y/__gcd(x, y);
        return res*z/__gcd(res, z*1ll);
    }
    
    int cnt(long long k, int x, int y, int z)
    {
        return k/x + k/y + k/z - k/lcm2(x, y) -k/lcm2(x, z) - k/lcm2(y, z) + k/lcm3(x, y, z);
    }
};