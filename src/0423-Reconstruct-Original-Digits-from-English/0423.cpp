class Solution {
 public:
  string originalDigits(string s) {
    int nums[10] = {};
    int cnt[26] = {};
    for (auto c : s) cnt[c - 'a']++;
    nums[0] = cnt['z' - 'a'];
    nums[2] = cnt['w' - 'a'];
    nums[4] = cnt['u' - 'a'];
    nums[6] = cnt['x' - 'a'];
    nums[8] = cnt['g' - 'a'];
    nums[1] = cnt['o' - 'a'] - nums[0] - nums[2] - nums[4];
    nums[3] = cnt['h' - 'a'] - nums[8];
    nums[5] = cnt['f' - 'a'] - nums[4];
    nums[7] = cnt['s' - 'a'] - nums[6];
    nums[9] = cnt['i' - 'a'] - nums[5] - nums[6] - nums[8];
    stringstream ss;
    for (int i = 0; i < 10; i++) {
      for (int j = 0; j < nums[i]; j++) {
        ss << i;
      }
    }
    return ss.str();
  }
};