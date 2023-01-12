class Solution {
 public:
  string evaluate(string s, vector<vector<string>>& knowledge) {
    unordered_map<string, string> m;
    for (auto& k : knowledge) {
      m[k[0]] = k[1];
    }

    stringstream os;
    int n = s.size();
    for (int i = 0; i < n; i++) {
      if (s[i] == '(') {
        i++;
        stringstream cur;
        while (i < n && s[i] != ')') {
          cur << s[i];
          i++;
        }

        auto& x = m[cur.str()];
        if (x.empty()) {
          os << '?';
        } else {
          os << x;
        }
      } else {
        os << s[i];
      }
    }
    return os.str();
  }
};