class Solution {
 public:
  int reinitializePermutation(int n) {
    if (n == 2) {
      return 1;
    }
    int s = 1, p = 2;
    while (p != 1) {
      s++;
      p = p * 2 % (n - 1);
    }
    return s;
  }
};