class Solution {
 public:
  string decodeMessage(string key, string message) {
    char chars[26];
    memset(chars, -1, 26);
    int t = 0;
    for (auto c : key) {
      if (c == ' ') continue;
      auto x = c - 'a';
      if (chars[x] == -1) {
        chars[x] = t++;
      }
    }
    for (auto& c : message) {
      if (c != ' ') {
        c = chars[c - 'a'] + 'a';
      }
    }
    return message;
  }
};