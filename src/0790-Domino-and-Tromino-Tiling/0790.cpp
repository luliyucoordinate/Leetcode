class Solution {
 public:
  int numTilings(int n) {
    if (n == 1) return 1;
    int mod = 1e9 + 7;
    long long a = 1, b = 1, c = 2;
    for (int i = 3; i <= n; ++i) {
      long long d = (c * 2 + a) % mod;
      a = b;
      b = c;
      c = d;
    }
    return c;
  }
};