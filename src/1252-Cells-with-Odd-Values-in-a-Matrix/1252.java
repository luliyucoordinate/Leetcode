class Solution {
    public int oddCells(int n, int m, int[][] indices) {
        int[] row = new int[n];
        int[] col = new int[m];
        int rowCnt = 0, colCnt = 0;
        for (int[] it : indices) {
            row[it[0]] ^= 1;
            col[it[1]] ^= 1;
            rowCnt += row[it[0]] == 1 ? 1 : -1;
            colCnt += col[it[1]] == 1 ? 1 : -1;
        }
        return m * rowCnt + n * colCnt - rowCnt * colCnt * 2;
    }
}