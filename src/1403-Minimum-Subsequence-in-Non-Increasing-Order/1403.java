class Solution {
    public List<Integer> minSubsequence(int[] nums) {
        Arrays.sort(nums);
        List<Integer> res = new ArrayList();
        int cur = 0, t = 0;
        
        for (int i : nums) t += i;
        t /= 2;
        
        for (int i = nums.length - 1; i >= 0; i--) {
            cur += nums[i];
            res.add(nums[i]);
            if (cur > t) return res;
        }
        return res;
    }
}