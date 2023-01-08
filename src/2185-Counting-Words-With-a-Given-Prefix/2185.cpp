class Solution {
 public:
  int prefixCount(vector<string>& words, string pref) {
    return count_if(words.begin(), words.end(), [&](auto& s) {
      return s.compare(0, pref.size(), pref) == 0;
    });
  }
};