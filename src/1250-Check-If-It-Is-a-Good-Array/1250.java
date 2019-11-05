class Solution 
{
    public boolean isGoodArray(int[] nums) 
    {
        int x = nums[0], y;
        for (int a : nums) {
            while (a > 0) {
                y = x % a;
                x = a;
                a = y;
            }
        }
        return x == 1;
    }
}