class Solution {
    public boolean canReach(int[] arr, int start) {
        Queue<Integer> q = new LinkedList();
        q.offer(start);
        boolean[] vis = new boolean[arr.length];
        vis[start] = true;
        
        while (!q.isEmpty()) {
            int cur = q.poll();
            if (arr[cur] == 0) return true;
            
            vis[cur] = true;
            int a = cur + arr[cur], b = cur - arr[cur];
            if (a >= 0 && a < arr.length && !vis[a]) q.offer(a);
            if (b >= 0 && b < arr.length && !vis[b]) q.offer(b);
        }
        return false;
    }
}