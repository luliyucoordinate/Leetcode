class Solution {
    private static final int[] d = {0, 0, 1, 0, -1, 0};

    public int minFlips(int[][] mat) {
        int start = 0, r = mat.length, c = mat[0].length;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                start |= mat[i][j] << i * c + j;
            }
        }

        Queue<Integer> q = new LinkedList(Arrays.asList(start));
        Set<Integer> seen = new HashSet();
        for (int step = 0; !q.isEmpty(); step++) {
            for (int qs = q.size(); qs > 0; qs--) {
                int cur = q.poll();
                if (cur == 0) return step;
                for (int i = 0; i < r; i++) {
                    for (int j = 0; j < c; j++) {
                        int ne = cur;
                        for (int k = 0; k < 5; k++) {
                            int x = d[k] + i, y = d[k + 1] + j;
                            if (x >= 0 && x < r && y >= 0 && y < c) {
                                ne ^= 1 << x * c + y;
                            }
                        }
                        if (!seen.contains(ne)) {
                            seen.add(ne);
                            q.offer(ne);
                        }
                    }
                }
            }
        }
        return -1;
    }
}