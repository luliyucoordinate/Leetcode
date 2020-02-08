class Solution {
    public boolean makesquare(int[] nums) {
        n = nums.length;
        for (int i : nums) s +=i;
        if (n < 4 || s % 4 > 0) return false;
        t = s / 4;
        vis = new int[n];
        
        Arrays.sort(nums);
        reverse(nums);
        return dfs(nums, 0, 0, 0);
    }
    
    private int n, s, t;
    private int[] vis;
    
    private boolean dfs(int[] nums, int cur, int u, int k) {
        if (u == 4) return true;
        if (cur == t) return dfs(nums, 0, u + 1, 0);
        
        for (int i = k, j; i < n; i++) {
            if (vis[i] == 1 || nums[i] + cur > t) continue;
            
            vis[i] = 1;
            if (dfs(nums, cur + nums[i], u, i + 1)) return true;
            vis[i] = 0;
            
            if (cur == 0 || cur + nums[i] == t) return false;
            
            j = i;
            while (j < n && nums[i] == nums[j]) j++;
            i = j - 1;
        }
        return false;
    }
    
    private void reverse(int[] nums) {
        int l = 0, r = nums.length - 1, t;
        while (l < r) {
            t = nums[r];
            nums[r--] = nums[l];
            nums[l++] = t;
        }
    }
}