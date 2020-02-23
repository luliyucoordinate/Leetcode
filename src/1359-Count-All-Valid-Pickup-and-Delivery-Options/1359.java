class Solution {
    public int countOrders(int n) {
        long res = 1, mod = (long)1e9 + 7;
        for (int i = 1; i <= n; ++i)
            res = res * (i * 2 - 1) * i % mod;
        return (int)res;
    }
}