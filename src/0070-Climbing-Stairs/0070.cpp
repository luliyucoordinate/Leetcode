class Solution {
 public:
  int climbStairs(int n) {
    long long a = 1, b = 1, c;
    for (int i = 0; i < n; i++) {
      c = a;
      a = b;
      b += c;
    }
    return a;
  }
};