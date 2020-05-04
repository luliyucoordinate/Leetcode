class Solution {
    public int[] findDiagonalOrder(List<List<Integer>> nums) {
        List<Deque<Integer>> mat = new ArrayList<>();
        int n = 0, k = 0;
        for (int i = 0; i < nums.size(); i++) {
            List<Integer> row = nums.get(i);
            for (int j = 0; j < row.size(); j++, n++) {
                if (i + j >= mat.size()) mat.add(new ArrayDeque());
                mat.get(i + j).push(row.get(j));
            }
        }
        
        int[] res = new int[n];
        for (Deque<Integer> diag : mat) {
            for (int num : diag) {
                res[k++] = num;
            }
        }
        return res;
    }
}