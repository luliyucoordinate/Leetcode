class Solution {
    public int[] processQueries(int[] queries, int m) {
        int n = queries.length;
        N = m + n + 1;
        
        int[] pos = new int[m + 1];
        int[] tree = new int[N];
        for (int i = 1; i <= m; i++) {
            pos[i] = n + i;
            update(tree, i + n, 1);
        }
        
        int[] res = new int[n];
        int t = 0;
        for (int i : queries) {
            res[t] = prefixSum(tree, pos[i] - 1);
            update(tree, pos[i], -1);
            update(tree, n, 1);
            pos[i] = n;
            t++;
            n--;
        }
        return res;
    }

    private int N;
    
    private void update(int[] tr, int x, int v) {
        for (int i = x; i < N; i += i & -i) {
            tr[i] += v;
        }
    }
    
    private int prefixSum(int[] tr, int x) {
        int res = 0;
        for (int i = x; i > 0; i -= i & -i) {
            res += tr[i];
        }
        return res;
    }
}