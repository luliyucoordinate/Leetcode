class Solution {
    public int[] sumZero(int n) {
        int[] res = new int[n];
        for (int i = 1 - n, j = 0; i < n; i += 2, j++) res[j] = i;
        return res;
    }
}