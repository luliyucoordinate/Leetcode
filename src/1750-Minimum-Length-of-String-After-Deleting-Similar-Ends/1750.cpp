class Solution {
 public:
  int minimumLength(string s) {
    int n = s.size();
    int i = 0, j = n - 1;
    while (i < j) {
      char p = s[i];
      if (p != s[j]) break;
      while (i <= j && p == s[i]) i++;
      while (i <= j && p == s[j]) j--;
    }
    return j - i + 1;
  }
};