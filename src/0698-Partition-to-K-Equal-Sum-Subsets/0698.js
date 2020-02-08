var canPartitionKSubsets = function(nums, k) {
    let n = nums.length, s = 0;
    for (let i of nums) s += i;
    if (s % k) return false;
    
    t = Math.floor(s / k);
    let vis = new Array(n);
    vis.fill(0);
    nums.sort((a, b) => b - a);
    
    let dfs = function(cur, u, p) {
        if (u == k) return true;
        if (cur == t) return dfs(0, u + 1, 0);
        
        for (let i = p, j; i < n; i++) {
            if (vis[i] || nums[i] + cur > t) continue;
            
            vis[i] = 1;
            if (dfs(cur + nums[i], u, i + 1)) return true;
            vis[i] = 0;
            
            if (cur == 0 || nums[i] + cur == t) return false;
            
            j = i;
            while (j < n && nums[i] == nums[j]) ++j;
            i = j - 1;
        }
        return false;
    }
    return dfs(0, 0, 0);
};