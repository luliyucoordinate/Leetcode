class Solution {
 public:
  vector<int> twoOutOfThree(vector<int>& nums1, vector<int>& nums2,
                            vector<int>& nums3) {
    int cnt[101] = {};
    for (auto& num : nums1) cnt[num] = 1;
    for (auto& num : nums2) cnt[num] |= 2;
    for (auto& num : nums3) cnt[num] |= 4;
    vector<int> res;
    for (int i = 0; i < 101; i++) {
      auto v = cnt[i];
      if (v & (v - 1)) res.push_back(i);
    }
    return res;
  }
};