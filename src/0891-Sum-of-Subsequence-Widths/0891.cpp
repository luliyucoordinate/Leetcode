class Solution 
{
public:
    int sumSubseqWidths(vector<int>& A) 
    {
        sort(A.begin(), A.end());
        int res = 0, mod = 1e9 + 7, n = A.size();
        for (int i = 0; i < n; i++)
        {
            res <<= 1;
            res -= A[i];
            res += A[n - i - 1];
            res %= mod;
        }
        return (res + mod)%mod;
    }
};