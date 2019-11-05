class Solution {
    public int numberOfSubarrays(int[] nums, int k) {
        return atMost(nums, k) - atMost(nums, k - 1);
    }
    private int atMost(int[] nums, int k) {
        int res = 0, i = 0;
        for (int j = 0; j < nums.length; j++) {
            k -= nums[j] % 2;
            while (k < 0) {
                k += nums[i++] % 2;
            }
            res += j - i + 1;
        }
        return res;
    }
}