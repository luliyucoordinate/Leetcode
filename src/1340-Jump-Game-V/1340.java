class Solution {
    public int maxJumps(int[] arr, int d) {
        n = arr.length; td = d;
        dp = new int[n];
        lb = new int[n];
        rb = new int[n];
        Arrays.fill(lb, -1);
        Arrays.fill(rb, -1);
        
        findBiggerLeft(arr, lb);
        findBiggerRight(arr, rb);

        int res = 0;
        for (int i = 0; i < n; i++) {
            res = Math.max(res, dfs(i));
        }
        return res;
    }
    
    private int[] dp, lb, rb;
    private int n, td;
    
    private void findBiggerRight(int[] arr, int[] res) {
        Deque<Integer> s = new LinkedList();
        for (int i = 0; i < n; i++) {
            while (!s.isEmpty() && s.getFirst() < i - td) s.removeFirst();
            while (!s.isEmpty() && arr[s.getLast()] < arr[i]) res[s.removeLast()] = i;
            s.addLast(i);
        }
    }

    private void findBiggerLeft(int[] arr, int[] res) {
        Deque<Integer> s = new LinkedList();
        for (int i = 0; i < n; i++) {
            while (!s.isEmpty() && s.getFirst() < i - td) s.removeFirst();
            while (!s.isEmpty() && arr[s.getLast()] <= arr[i]) s.removeLast();
            if (!s.isEmpty()) res[i] = s.getLast();
            s.addLast(i);
        }
    }
    
    private int dfs(int u) {
        if (dp[u] > 0) return dp[u];
        dp[u] = 1;
        if (lb[u] >= 0) dp[u] = Math.max(dp[u], dfs(lb[u]) + 1);
        if (rb[u] >= 0) dp[u] = Math.max(dp[u], dfs(rb[u]) + 1);
        return dp[u];
    }
}