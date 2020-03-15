class Solution {
    public List<Integer> luckyNumbers (int[][] A) {
        int r = A.length, c = A[0].length;
        List<Integer> res = new ArrayList();
        
        for (int i = 0; i < r; i++) {
            int minv = 100000, minp = -1;
            for (int j = 0; j < c; j++) {
                if (A[i][j] < minv) {
                    minv = A[i][j];
                    minp = j;
                }
            }
            
            boolean flag = false;
            for (int j = 0; j < r; j++) {
                if (A[j][minp] > minv) {
                    flag = true;
                    break;
                }
            }
            if (!flag) res.add(minv);
        }
        return res;
    }
}