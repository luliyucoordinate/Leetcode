class Solution {
public:
    string findLongestWord(string s, vector<string>& dictionary) {
        const int n = s.size();
        int f[n + 1][26];
        memset(f[n], -1, sizeof(f[n]));

        for (int i = n - 1; ~i; i--) {
            for (int j = 0; j < 26; j++) {
                if (s[i] == j + 97) f[i][j] = i;
                else f[i][j] = f[i + 1][j];
            }
        }

        string_view res = "";
        for (auto& w : dictionary) {
            bool match = true;
            int j = 0;
            for (auto& c : w) {
                if (f[j][c - 97] == -1) {
                    match = false;
                    break;
                }
                j = f[j][c - 97] + 1;
            }
            if (match) {
                if (res.size() < w.size() ||
                    (res.size() == w.size() && res > w)) {
                    res = w;
                }
            }
        }
        return string(res);
    }
};