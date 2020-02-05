class Solution {
    public int maxValueAfterReverse(int[] nums) {
        int n = nums.length, res = 0, total = 0, Hi = 100010, Lj = -100010;
        for (int i = 0; i < n - 1; i++) {
            int a = nums[i], b = nums[i + 1];
            total += Math.abs(a - b);
            Hi = Math.min(Hi, Math.max(a, b));
            Lj = Math.max(Lj, Math.min(a, b));
            res = Math.max(res, Math.max(Math.abs(nums[0] - b) - Math.abs(a - b),
                                        Math.abs(a - nums[n-1]) - Math.abs(a - b)));
            res = Math.max(res, (Lj - Hi) * 2);
        }
        return total + res;
    }
}