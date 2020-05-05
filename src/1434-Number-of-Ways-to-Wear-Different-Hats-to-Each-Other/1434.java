class Solution {
    public int numberWays(List<List<Integer>> hats) {
        int n = hats.size(), mod = 1000000007;
        int[][] f = new int[2][1024];
        f[0][0] = 1;
        
        List<Integer>[] a = new List[41];
        for (int i = 1; i <= 40; i++) a[i] = new ArrayList();
        for (int i = 0; i < n; i++) {
            for (int hat : hats.get(i)) {
                a[hat].add(i);
            }
        }
        
        for (int i = 1; i <= 40; i++) {
            for (int j = 0; j < (1 << n); j++) {
                f[i % 2][j] = f[(i - 1) % 2][j];
                for (int x : a[i]) {
                    if (((j >> x) & 1) != 0) {
                        f[i % 2][j] += f[(i - 1) % 2][j ^ (1 << x)];
                        f[i % 2][j] %= mod;
                    }
                }
            }
        }
        return f[0][(1 << n) - 1];
    }
}