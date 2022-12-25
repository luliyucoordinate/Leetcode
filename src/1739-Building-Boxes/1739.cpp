class Solution {
 public:
  int minimumBoxes(int n) {
    int x = cbrt(6L * n);
    int res = x * (x + 1) / 2;
    int max_n = x * (x + 1ll) * (x + 2ll) / 6ll;
    if (max_n > n) {
      max_n -= res;
      res -= x;
    }
    return res + ceil((-1 + sqrt(1 + 8 * (n - max_n))) / 2);
  }
};
