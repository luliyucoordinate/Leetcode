class Solution {
 public:
  Solution(vector<int>& nums) {
    this->nums = nums;
    this->org = nums;
  }

  vector<int> reset() {
    nums = org;
    return nums;
  }

  vector<int> shuffle() {
    for (int i = 0; i < nums.size(); i++) {
      int j = i + rand() % (nums.size() - i);
      swap(nums[i], nums[j]);
    }
    return nums;
  }

 private:
  vector<int> nums, org;
};