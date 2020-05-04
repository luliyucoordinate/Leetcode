class Solution {
public:
    int maxScore(string s) {
        int zeros = 0, ones = 0, res = -1000, n = s.size();
        for (int i = 0; i < n; i++) {
            if (s[i] == '1') ones++;
            else zeros++;
            if (i != n - 1) res = max(res, zeros - ones);
        }
        return res + ones;
    }
};