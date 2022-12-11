class Solution {
 public:
  int minOperations(vector<int>& nums) {
    int res = 0;
    int p = 0;
    for (auto& num : nums) {
      if (num <= p) {
        p++;
        res += p - num;
      } else {
        p = num;
      }
    }
    return res;
  }
};