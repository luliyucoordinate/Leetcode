class Solution {
    public int maxSumDivThree(int[] nums) {
        int[] res = new int[3];
        for (int a : nums) {
            int[] tmp = res.clone();
            for (int i : tmp) {
                res[(i + a)%3] = Math.max(res[(i + a)%3], i + a);
            }
        }
        return res[0];
    }
}