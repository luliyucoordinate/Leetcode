class Solution {
    public List<List<Integer>> removeInterval(int[][] intervals, int[] toBeRemoved) {
        List<List<Integer>> res = new ArrayList();
        for (int[] inter : intervals) {
            if (inter[1] <= toBeRemoved[0] || inter[0] >= toBeRemoved[1]) {
                res.add(Arrays.asList(inter[0], inter[1]));
            } else {
                if (inter[0] < toBeRemoved[0]) res.add(Arrays.asList(inter[0], toBeRemoved[0]));
                if (inter[1] > toBeRemoved[1]) res.add(Arrays.asList(toBeRemoved[1], inter[1]));
            }
        }
        return res;
    }
}