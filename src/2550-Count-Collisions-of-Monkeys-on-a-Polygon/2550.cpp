class Solution {
 public:
  int monkeyMove(int n) {
    int mod = 1e9 + 7;
    auto qmi = [&](long a, long b, int p) {
      long long res = 1;
      while (b) {
        if (b & 1) res = res * a % p;
        a = a * a % p;
        b >>= 1;
      }
      return res;
    };

    return (qmi(2, n, mod) - 2 + mod) % mod;
  }
};