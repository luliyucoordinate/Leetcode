class Solution {
    public int makeConnected(int n, int[][] connections) {
        if (connections.length < n - 1) return -1;
        parent = new int[n];
        for (int i = 0; i < n; i++) parent[i] = i;
        
        int res = n;
        for (int[] it : connections) {
            int x = find(it[0]), y = find(it[1]);
            if (x != y) {
                parent[x] = y;
                res--;
            }
        }
        return res - 1;
    }
    
    private int[] parent;
    
    private int find(int x) {
        if (x != parent[x]) parent[x] = find(parent[x]);
        return parent[x];
    }
}