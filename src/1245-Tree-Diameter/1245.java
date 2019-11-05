class Solution {
    private Map<Integer, List<Integer>> g = new HashMap();
    private int res;
    
    public int treeDiameter(int[][] edges) {
        for (int[] it : edges) {
            if (!g.containsKey(it[0])) g.put(it[0], new ArrayList());
            if (!g.containsKey(it[1])) g.put(it[1], new ArrayList());
            g.get(it[0]).add(it[1]);
            g.get(it[1]).add(it[0]);
        }
        dfs(0, -1);
        return res;
    }
    
    private int dfs(int cur, int pre) {
        int d1 = 0, d2 = 0;
        for (int i : g.get(cur)) {
            if (i != pre) {
                int d = dfs(i, cur);
                if (d > d1) {
                    int tmp = d1; d1 = d; d2 = tmp;
                } else if (d > d2) d2 = d;
            }
        }
        res = Math.max(res, d1 + d2);
        return d1 + 1;
    }
}