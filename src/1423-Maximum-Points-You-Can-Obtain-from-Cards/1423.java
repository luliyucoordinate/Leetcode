class Solution {
    public int maxScore(int[] cardPoints, int k) {
        int res = 0, cur = 0, n = cardPoints.length;
        for (int i = n - k; i < n + k; i++) {
            cur += cardPoints[i % n];
            if (i >= n) cur -= cardPoints[i - k];
            res = Math.max(res, cur);
        }
        return res;
    }
}