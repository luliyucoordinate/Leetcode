class Solution {
    public int countLargestGroup(int n) {
        int[] cnt = new int[37];
        int mx = 0;
        
        for (int i = 1; i <= n; ++i) {
            int c = 0, x = i;
            while (x > 0) {
                c += x % 10;
                x /= 10;
            }
            cnt[c]++;
            mx = Math.max(mx, cnt[c]);
        }
        
        int res = 0;
        for (int i : cnt) {
            if (i == mx) res++;
        }
        return res;
    }
}