class Solution {
    public double frogPosition(int n, int[][] edges, int t, int target) {
        if (n == 1) return 1.0;
        
        g = new List[n + 1];
        this.target = target;
        for (int i = 0; i <= n; i++) g[i] = new ArrayList();
        for (int[] it : edges) {
            g[it[0]].add(it[1]);
            g[it[1]].add(it[0]);
        }
        return dfs(-1, 1, t);
    }
    
    private List<Integer>[] g;
    private int target;
    
    private double dfs(int fa, int cur, int t) {
        if (cur != 1 && g[cur].size() == 1 || t == 0) {
            return cur == target ? 1 : 0;
        }
        
        double res = 0.0;
        for (int i : g[cur]) {
           if (i != fa) res = Math.max(res, dfs(cur, i, t - 1));
        }
        return res / (g[cur].size() - (cur != 1 ? 1 : 0));
    }
}