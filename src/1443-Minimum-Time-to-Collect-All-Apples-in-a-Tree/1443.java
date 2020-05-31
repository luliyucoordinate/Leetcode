class Solution {
    public int minTime(int n, int[][] edges, List<Boolean> hasApple) {
        for (int[] it : edges) {
            int i = it[0], j = it[1];
            g.putIfAbsent(i, new ArrayList());
            g.putIfAbsent(j, new ArrayList());
            g.get(i).add(j);
            g.get(j).add(i);
        }
        
        boolean[] vis = new boolean[n];
        vis[0] = true;
        return dfs(0, hasApple, vis);
    }
    
    private Map<Integer, List<Integer>> g = new HashMap();
    
    private int dfs(int x, List<Boolean> hasApple, boolean[] vis) {
        int res = 0;
        for (int i : g.get(x)) {
            if (vis[i]) continue;
            vis[i] = true;
            
            int cur = dfs(i, hasApple, vis);
            if (cur > 0) res += cur + 2;
            else if (hasApple.get(i)) res += 2;
        }
        return res;
    }
}