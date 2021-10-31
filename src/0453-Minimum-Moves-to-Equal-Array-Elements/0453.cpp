class Solution {
 public:
  int minMoves(vector<int>& nums) {
    int minNum = *min_element(nums.begin(), nums.end());
    int res = 0;
    for (int num : nums) {
      res += num - minNum;
    }
    return res;
  }
};