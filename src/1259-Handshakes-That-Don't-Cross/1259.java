class Solution {
    public int numberOfWays(int n) {
        long[] inv = new long[n / 2 + 2];
        inv[1] = 1;
        long mod = 1000000007, res = 1;
        for (int i = 2; i < n / 2 + 2; i++) {
            inv[i] = mod - mod / i * inv[(int)mod%i]%mod;
        }
        for (int i = 1; i < n/ 2 + 1; i++) {
            res = res * (i + n / 2) % mod;
            res = res * inv[i] % mod;
        }
        return (int)(res * inv[n / 2 + 1] % mod);
    }
}