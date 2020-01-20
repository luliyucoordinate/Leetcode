class Solution {
    public int videoStitching(int[][] clips, int T) {
        Arrays.sort(clips, (a,b) ->  a[0] - b[0]);
        int pre = -1, cur = 0, step = 0;
        for (int[] it : clips) {
            if (cur >= T || it[0] > cur) break;
            if (pre < it[0] && it[0] <= cur) {
                step++;
                pre = cur;
            }
            cur = Math.max(cur, it[1]);
        }
        return cur >= T ? step : -1;
    }
}