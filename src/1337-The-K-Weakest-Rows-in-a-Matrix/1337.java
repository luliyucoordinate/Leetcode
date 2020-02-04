class Solution {
    public int[] kWeakestRows(int[][] mat, int k) {
        PriorityQueue<int[]> q = new PriorityQueue<>((a, b) -> a[0] == b[0] ? b[1] - a[1] : b[0] - a[0]);
        for (int i = 0; i < mat.length; i++) {
            q.offer(new int[]{numOnes(mat[i]), i});
            if (q.size() > k) q.poll();
        }
        
        int[] res = new int[k];
        for (int i = k - 1; i >= 0; i--) {
            res[i] = q.poll()[1];
        }
        return res;
    }
    
    private int numOnes(int[] row) {
        int l = 0, r = row.length;
        while (l < r) {
            int mid = (l + r) >> 1;
            if (row[mid] == 1) l = mid + 1;
            else r = mid;
        }
        return l;
    }
}