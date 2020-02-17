class Solution {
    public int maxEvents(int[][] events) {
        Arrays.sort(events, (a, b) -> a[0] - b[0]);
        Queue<Integer> q = new PriorityQueue();
        int res = 0, index = 0, n = events.length;
        
        int l = 100000, r = 0;
        for (int[] it : events) {
            l = Math.min(it[0], l);
            r = Math.max(it[1], r);
        }
        
        for (int i = l; i <= r; i++) {
            while (index < n && events[index][0] <= i) {
                q.add(events[index][1]);
                index++;
            }
            
            if (q.isEmpty() && index == n) return res;
            
            while (!q.isEmpty()) {
                int pre = q.poll();
                if (i <= pre) {
                    res++;
                    break;
                }
            }
        }
        return res;
    }
}