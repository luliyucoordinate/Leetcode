var makesquare = function(nums) {
    let n = nums.length, s = 0;
    for (let i of nums) s += i;
    if (n < 4 || s % 4) return false;
    
    t = Math.floor(s / 4);
    let vis = new Array(n);
    vis.fill(0);
    nums.sort((a, b) => b - a);
    
    let dfs = function(cur, u, k) {
        if (u == 4) return true;
        if (cur == t) return dfs(0, u + 1, 0);
        
        for (let i = k, j; i < n; i++) {
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