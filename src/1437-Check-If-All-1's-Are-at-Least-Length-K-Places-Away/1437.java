class Solution {
    public boolean kLengthApart(int[] nums, int k) {
        for(int pre = -k - 1, i = 0; i < nums.length; i++) {
            if (nums[i] == 1) {
                if (i - pre <= k) return false;
                pre = i;
            }
        }
	    return true;
    }
}