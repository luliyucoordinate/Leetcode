class Solution {
    public int maxPerformance(int n, int[] s, int[] e, int k) {
        int[][] engineers = new int[n][2];
        for (int i = 0; i < n; ++i)
            engineers[i] = new int[]{e[i], s[i]};
        
        Arrays.sort(engineers, (a, b) -> Integer.compare(b[0], a[0]));
        long res = 0, sSum = 0;
        PriorityQueue<Integer> pq = new PriorityQueue();
        
        for (int[] engineer : engineers) {
            sSum += engineer[1];
            res = Math.max(res, sSum * engineer[0]);
            pq.add(engineer[1]);
            if (pq.size() >= k) sSum -= pq.poll();
        }
        return (int) (res % (long)(1e9 + 7));
    }
}