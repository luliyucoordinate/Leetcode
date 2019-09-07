class Solution 
{
public:
    int numPrimeArrangements(int n) 
    {
        vector<int> primes(n + 1, 0);
        vector<int> st(n + 1, 0);
        int cnt = 0, MOD = int(1e9 + 7);
        for (int i = 2; i <= n; ++i)
        {
            if (!st[i]) primes[cnt++] = i;
            for (int j = 0; primes[j] <= n/i; ++j) 
            {
                st[primes[j]*i] = 1;
                if (i % primes[j] == 0) break;
            }
        }

        long long res = 1;
        for (int i = 1; i <= cnt; ++i) res = res*i%MOD;
        for (int i = 1; i <= n - cnt; ++i) res = res*i%MOD;
        return res;
    }
};