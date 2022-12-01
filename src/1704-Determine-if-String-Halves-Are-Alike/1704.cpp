class Solution {
 public:
  bool halvesAreAlike(string s) {
    int c1 = 0, c2 = 0;
    int n = s.size();
    for (int i = 0, j = s.size() - 1; i < j; i++, j--) {
      if (a.count(s[i])) c1++;
      if (a.count(s[j])) c2++;
    }
    return c1 == c2;
  }

  unordered_set<char> a = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
};