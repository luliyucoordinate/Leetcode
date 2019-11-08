class Solution {
    public int maxProfitAssignment(int[] difficulty, int[] profit, int[] worker) {
        List<int[]> jobs = new ArrayList();
        int N = profit.length, res = 0, i = 0, best = 0;
        for (int j = 0; j < N; ++j)
            jobs.add(new int[]{difficulty[j], profit[j]});
        Collections.sort(jobs, new Comparator<int[]>() {
            @Override
            public int compare(int[] o1, int[] o2) {
                if (o1[0] == o2[0]) return o1[1] - o2[1];
                return o1[0] - o2[0];
            }
        });
        Arrays.sort(worker);
        for (int w : worker) {
            while (i < N && w >= jobs.get(i)[0])
                best = Math.max(jobs.get(i++)[1], best);
            res += best;
        }
        return res;
    }
}