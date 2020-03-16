class Solution {
    public double mincostToHireWorkers(int[] q, int[] w, int K) {
        double[][] workers = new double[q.length][2];
        for (int i = 0; i < q.length; ++i)
            workers[i] = new double[]{(double)w[i] / q[i], (double)q[i]};
        
        Arrays.sort(workers, (a, b) -> Double.compare(a[0], b[0]));
        double res = Double.MAX_VALUE, qsum = 0;
        PriorityQueue<Double> pq = new PriorityQueue<>();
        
        for (double[] worker : workers) {
            qsum += worker[1];
            if (pq.size() == K - 1) res = Math.min(res, qsum * worker[0]);
            pq.add(-worker[1]);
            if (pq.size() >= K) qsum += pq.poll();
        }
        return res;
    }
}