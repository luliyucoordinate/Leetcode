class Solution {
    public int numSubmatrixSumTarget(int[][] A, int target) {
        int r = A.length, c = A[0].length;
        for (int[] row : A) {
            for (int i = 1; i < c; i++) row[i] += row[i - 1];
        }
        
        int res = 0, cur = 0;
        Map<Integer, Integer> cnt = new HashMap();
        for (int i = 0; i < c; i++) {
            for (int j = i; j < c; j++) {
                cnt.clear();
                cnt.put(0, 1);
                cur = 0;
                for (int k = 0; k < r; k++) {
                    cur += A[k][j] - (i > 0 ? A[k][i - 1] : 0);
                    res += cnt.getOrDefault(cur - target, 0);
                    cnt.put(cur, cnt.getOrDefault(cur, 0) + 1);
                }
            }
        }
        return res;
    }
}