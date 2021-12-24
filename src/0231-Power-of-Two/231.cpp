class Solution {
 public:
  bool isPowerOfTwo(int n) {
    return n < 0 ? false : __builtin_popcountll(n) == 1;
  }
};