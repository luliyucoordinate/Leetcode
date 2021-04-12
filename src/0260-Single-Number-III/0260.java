class Solution {
    public int[] singleNumber(int[] nums) {
        int tmp = nums[0];
        for(int i=1; i < nums.length; i++)
            tmp ^= nums[i];
        tmp = tmp & ~(tmp-1);
        int[] res = new int[2];
        for(int n : nums)
            if( (n & tmp) == 0)
                res[0] ^= n;
            else
                res[1] ^= n;
        return res;
    }
}
