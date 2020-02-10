class Solution {
    public int minJumps(int[] arr) {
        Map<Integer, List<Integer>> g = new HashMap();
        Set<Integer> values = new HashSet();
        int n = arr.length, step = 0;
        for (int i = 0; i < n; i++) {
            g.putIfAbsent(arr[i], new ArrayList());
            g.get(arr[i]).add(i);
        }
        
        int[] vis = new int[n];
        vis[0] = 1;
        
        Queue<Integer> q = new LinkedList();
        q.add(0);
        
        while (!q.isEmpty()) {
            int k = q.size();
            while (k-- > 0) {
                int pre = q.poll();
                if (pre == n - 1) return step;
                
                if (pre - 1 >= 0 && vis[pre - 1] == 0) {
                    vis[pre - 1] = 1; 
                    q.add(pre - 1);
                }
                
                if (pre + 1 < n && vis[pre + 1] == 0) {
                    vis[pre + 1] = 1; 
                    q.add(pre + 1);
                }
                
                if (values.contains(arr[pre])) continue;
                values.add(arr[pre]);
                for (int i : g.get(arr[pre])) {
                    if (vis[i] == 0) {
                        vis[i] = 1; 
                        q.add(i);
                    }
                }
            }
            step++;
        }
        return step;
    } 
}