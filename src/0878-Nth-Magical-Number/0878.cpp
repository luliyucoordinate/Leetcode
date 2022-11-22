class Solution {
 public:
  int nthMagicalNumber(int n, int a, int b) {
    int mod = 1e9 + 7;
    long long c = lcm(a, b);
    long long l = min(a, b), r = min(a, b) * (long long)n;
    while (l < r) {
      long long mid = (l + r) >> 1;
      long long x = mid / a + mid / b - mid / c;
      if (x >= n)
        r = mid;
      else
        l = mid + 1;
    }
    return l % mod;
  }
};