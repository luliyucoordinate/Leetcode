class Solution {
public:
    int countLargestGroup(int n) {
        int cnt[37] = {}, mx = 0;

        for (int i = 1; i <= n; ++i) {
            int c = 0, x = i;
            while (x > 0) {
                c += x % 10;
                x /= 10;
            }
            mx = max(mx, ++cnt[c]);
        }
        return count_if(begin(cnt), end(cnt), [&mx](int n) { return n == mx; });
    }
};