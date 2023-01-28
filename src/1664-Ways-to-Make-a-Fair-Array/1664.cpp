class Solution {
 public:
  int waysToMakeFair(vector<int>& nums) {
    int n = nums.size();
    int s = 0, res = 0;
    for (int i = 0; i < n; i++) {
      s += i & 1 ? nums[i] : -nums[i];
    }

    for (int i = 0; i < n; i++) {
      s -= i & 1 ? nums[i] : -nums[i];
      if (s == 0) res++;
      s -= i & 1 ? nums[i] : -nums[i];
    }
    return res;
  }
};