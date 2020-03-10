class Solution {
    public int numOfMinutes(int n, int headID, int[] manager, int[] informTime) {
        son = new List[n];
        for (int i = 0; i < n; i++) son[i] = new ArrayList();
        for (int i = 0; i < n; i++) if (manager[i] != -1) son[manager[i]].add(i);
        return dfs(headID, informTime);
    }
    
    private List<Integer>[] son;
    
    private int dfs(int x, int[] informTime) {
        int res = 0;
        for (int n : son[x])
            res = Math.max(res, dfs(n, informTime));
        return res + informTime[x];
    }
}