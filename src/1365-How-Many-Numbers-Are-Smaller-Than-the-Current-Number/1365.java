class Solution {
    public int[] smallerNumbersThanCurrent(int[] nums) {
        int[] cnt = new int[101];
        int[] res = new int[nums.length];
        
        for (int i : nums) cnt[i]++;
        
        for (int i = 1; i <= 100; i++) {
            cnt[i] += cnt[i - 1];    
        }
        
        for (int i = 0; i < nums.length; i++) {
            if (nums[i] != 0) res[i] = cnt[nums[i] - 1];
        }
        return res;     
    }
}