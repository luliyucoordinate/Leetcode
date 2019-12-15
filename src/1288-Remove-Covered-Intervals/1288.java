class Solution {
    public int removeCoveredIntervals(int[][] A) {
        int res = 0, r = 0;
        Arrays.sort(A, (a, b) -> a[0] != b[0] ? a[0] - b[0] : b[1] - a[1]);
        for (int[] v : A) {
            if (v[1] > r) ++res;
            r = Math.max(r, v[1]);
        }
        return res;
    }
}