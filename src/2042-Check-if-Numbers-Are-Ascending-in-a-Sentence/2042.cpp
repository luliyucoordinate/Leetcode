class Solution {
 public:
  bool areNumbersAscending(string s) {
    int p = 0, cur = 0;
    for (auto c : s) {
      if (isdigit(c)) {
        cur = cur * 10 + c - '0';
      } else if (cur != 0) {
        if (p >= cur) return false;
        p = cur;
        cur = 0;
      }
    }
    return cur == 0 || p < cur;
  }
};