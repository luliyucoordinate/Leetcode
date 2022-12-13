class Solution {
 public:
  bool checkIfPangram(string sentence) {
    int cnt[26] = {};
    for (auto c : sentence) {
      cnt[c - 'a']++;
    }
    bool res = true;
    for (int i = 0; i < 26; i++) {
      res &= (cnt[i] >= 1);
    }
    return res;
  }
};
