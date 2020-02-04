var maxJumps = function(arr, d) {
    let n = arr.length;
    let dp = new Array(n); dp.fill(0);
    let lb = new Array(n); lb.fill(-1);
    let rb = new Array(n); rb.fill(-1);
    
    let findBiggerLeft = function() {
        let s = [];
        for (let i = 0; i < n; i++) {
            while (s.length > 0 && s[0] < i - d) s.shift();
            while (s.length > 0 && arr[s[s.length-1]] <= arr[i]) s.pop();
            if (s.length > 0) lb[i] = s[s.length - 1];
            s.push(i);
        }
    }
    
    let findBiggerRight = function() {
        let s = [];
        for (let i = 0; i < n; i++) {
            while (s.length > 0 && s[0] < i - d) s.shift();
            while (s.length > 0 && arr[s[s.length-1]] < arr[i]) rb[s.pop()] = i;
            s.push(i);
        }
    }
    
    let dfs = function(u) {
        if (dp[u] > 0) return dp[u];
        dp[u] = 1;
        if (lb[u] >= 0) dp[u] = Math.max(dp[u], dfs(lb[u]) + 1);
        if (rb[u] >= 0) dp[u] = Math.max(dp[u], dfs(rb[u]) + 1);
        return dp[u];
    }
    
    findBiggerLeft();
    findBiggerRight();
    let res = 0;
    for (let i = 0; i < n; i++) {
        res = Math.max(res, dfs(i));
    }
    return res;
};