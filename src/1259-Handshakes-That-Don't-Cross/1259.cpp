class Solution 
{
public:
    int numberOfWays(int n) 
    {
        vector<long long> inv(n / 2 + 2, 0);
        inv[1] = 1;
        long long mod = 1e9 + 7, res = 1;
        for (int i = 2; i < n / 2 + 2; i++) 
        {
            inv[i] = mod - mod / i * inv[mod%i]%mod;
        }
        for (int i = 1; i < n/ 2 + 1; i++) 
        {
            res = res * (i + n / 2) % mod;
            res = res * inv[i] % mod;
        }
        return res * inv[n / 2 + 1] % mod;
    }
};