class Solution {
 public:
  vector<int> majorityElement(vector<int>& nums) {
    int a = 0, b = 0, cnt1 = 0, cnt2 = 0;
    for (auto num : nums) {
      if (cnt1 && a == num) {
        cnt1++;
      } else if (cnt2 && b == num) {
        cnt2++;
      } else if (cnt1 == 0) {
        cnt1++;
        a = num;
      } else if (cnt2 == 0) {
        cnt2++;
        b = num;
      } else {
        cnt1--, cnt2--;
      }
    }
    
    cnt1 = 0, cnt2 = 0;
    for (auto num : nums) {
      if (a == num)
        cnt1++;
      else if (b == num)
        cnt2++;
    }

    vector<int> res;
    if (cnt1 > nums.size() / 3) res.emplace_back(a);
    if (cnt2 > nums.size() / 3) res.emplace_back(b);
    return res;
  }
};