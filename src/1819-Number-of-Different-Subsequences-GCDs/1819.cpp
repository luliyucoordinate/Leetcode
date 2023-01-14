class Solution {
 public:
  int countDifferentSubsequenceGCDs(vector<int>& nums) {
    int res = 0, x = *max_element(nums.begin(), nums.end());
    vector<bool> has(x + 1);
    for (auto& num : nums) {
      if (!has[num]) {
        has[num] = true;
        res++;
      }
    }

    for (int i = 1; i <= x / 3; i++) {
      if (has[i]) continue;
      int g = 0;
      for (int j = i * 2; j <= x && j != g; j += i) {
        if (has[j]) {
          g = gcd(g, j);
        }
      }
      if (g == i) res++;
    }
    return res;
  }
};