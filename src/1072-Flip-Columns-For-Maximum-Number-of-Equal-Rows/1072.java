class Solution {
    public int maxEqualRowsAfterFlips(int[][] matrix) {
        Map<String, Integer> m = new HashMap<>();
        int res = 0;
        
        for (int[] row : matrix) {
            StringBuilder s = new StringBuilder();
            for (int r : row) s.append(r ^ row[0]);
            String str = s.toString();
            m.put(str, m.getOrDefault(str, 0) + 1);
            res = Math.max(res, m.get(str));
        }
        return res;
    }
}