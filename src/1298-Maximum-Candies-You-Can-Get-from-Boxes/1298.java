class Solution {
    public int maxCandies(int[] status, int[] candies, int[][] keys, int[][] containedBoxes, int[] initialBoxes) {
        Queue<Integer> q = new LinkedList();
        for (int i : initialBoxes) q.offer(i);
        int res = 0;

        while (!q.isEmpty()) {
            Boolean changed = false;
            for (int q_len = q.size(); q_len > 0; q_len--) {
                int b = q.poll();
                if (status[b] == 1) {
                    changed = true;
                    res += candies[b];
                    for (int i : containedBoxes[b]) q.offer(i);
                    for (int i : keys[b]) status[i] = 1;
                } else q.offer(b);
            }
            if (!changed) return res;
        }
        return res;
    }
}