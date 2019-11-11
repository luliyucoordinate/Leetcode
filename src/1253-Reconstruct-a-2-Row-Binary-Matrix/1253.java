class Solution {
    public List<List<Integer>> reconstructMatrix(int u, int l, int[] cs) {
        boolean[][] res = new boolean[2][cs.length];
        for (int i = 0; i < cs.length; ++i) {
            res[0][i] = cs[i] == 2 || (cs[i] == 1 && l < u);
            res[1][i] = cs[i] == 2 || (cs[i] == 1 && !res[0][i]);
            u -= res[0][i] ? 1 : 0;
            l -= res[1][i] ? 1 : 0;
        }
        return l == 0 && u == 0 ? new ArrayList(Arrays.asList(res[0], res[1])) : new ArrayList();
    }
}