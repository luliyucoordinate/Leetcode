class Solution {
    public int smallestDivisor(int[] A, int t) {
        int l = 1, r = (int)1e6, m, sum;
        while (l < r) {
            m = (l + r) >> 1;
            sum = 0;
            for (int i : A) sum += (i + m - 1) / m;
            if (sum > t) l = m + 1;
            else r = m;
        }
        return l;
    }
}