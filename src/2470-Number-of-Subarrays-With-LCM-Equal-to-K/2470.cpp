class Solution {
 public:
  int subarrayLCM(vector<int>& nums, int k) {
    unordered_map<int, int> pre;
    int res = 0;
    for (auto& num : nums) {
      unordered_map<int, int> cur;
      if (k % num == 0) {
        pre[num]++;
        for (auto& [a, b] : pre) {
          cur[lcm(a, num)] += b;
        }
        res += cur[k];
      }
      swap(pre, cur);
    }
    return res;
  }
};