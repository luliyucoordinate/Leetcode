class Solution {
    public int minTaps(int n, int[] ranges) {
        int[] data = new int[n + 1];
        for (int i = 0; i < ranges.length; i++) {
            int l = Math.max(0, i - ranges[i]), r = Math.min(n, i + ranges[i]);
            data[l] = Math.max(data[l], r - l);
        }
        
        int pre = -1, cur = 0, step = 0;
        for (int i = 0; i <= n; i++) {
            if (cur < i) return -1;
            if (cur >= n) return step;
            if (pre < i && i <= cur) {
                step++;
                pre = cur;
            }
            cur = Math.max(cur, i + data[i]);
        }
        return step;
    }
}