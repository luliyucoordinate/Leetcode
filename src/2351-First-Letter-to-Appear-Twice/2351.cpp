class Solution {
 public:
  char repeatedCharacter(string s) {
    int cnt[26] = {};
    for (auto c : s) {
      auto x = c - 'a';
      if (cnt[x]) return c;
      cnt[x]++;
    }
    return ' ';
  }
};