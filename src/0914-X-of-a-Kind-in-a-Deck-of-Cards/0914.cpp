class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        int cnt[10000] = {};
        for (int d : deck) cnt[d]++;

        int res = -1;
        for (int i = 0; i < 10000; i++) {
            if (cnt[i]) {
                if (res == -1) res = cnt[i];
                else res = gcd(res, cnt[i]);
            }
        }
        return res >= 2;
    }
};