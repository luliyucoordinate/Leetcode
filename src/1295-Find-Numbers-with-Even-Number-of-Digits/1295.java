class Solution {
    public int findNumbers(int[] nums) {
        int res = 0;
		for (int i = 0; i < nums.length; i++) {
			double value = (double) nums[i];
			double x = Math.log(value) / Math.log(10);
			if (((int)(x+1)) % 2 == 0) res++;
		}
		return res;
    }
}