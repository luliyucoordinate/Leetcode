class Solution {
 public:
  int countOdds(int low, int high) {
    return (high - low) / 2 + (low & 1 || high & 1 ? 1 : 0);
  }
};