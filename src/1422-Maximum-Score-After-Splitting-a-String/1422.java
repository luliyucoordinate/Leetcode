class Solution {
    public int maxScore(String s) {
        int zeros = 0, ones = 0, res = -1000, n = s.length();
        for (int i = 0; i < n; i++) {
            if (s.charAt(i) == '1') ones++;
            else zeros++;
            if (i != n - 1) res = Math.max(res, zeros - ones);
        }
        return res + ones;
    }
}