class Solution {
    public int minimumMoves(int[] arr) {
        int n = arr.length;
        int[][] mem = new int[n + 1][n + 1];
        for (int l = 1; l <= n; l++) {
            int i = 0, j = l - 1;
            while (j < n) {
                if (l == 1) mem[i][j] = 1;
                else {
                    mem[i][j] = 1 + mem[i + 1][j];
                    for (int k = i + 1; k <= j; k++) {
                        if (arr[k] == arr[i])
                            mem[i][j] = Math.min(mem[i][j], mem[i + 1][k - 1] + mem[k + 1][j] + (i + 1 == k ? 1 : 0));
                    }
                }
                ++i; ++j;
            }
        }
        return mem[0][n - 1];
    }
}