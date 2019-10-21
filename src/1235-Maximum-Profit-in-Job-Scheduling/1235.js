var jobScheduling = function(startTime, endTime, profit) {
    let n = startTime.length, jobs = [];
    for (let i = 0; i < n; i++) {
        jobs.push([startTime[i], endTime[i], profit[i]]);
    }
    jobs.sort(function(a, b) {
        return a[1] - b[1];
    });
    
    let dp = new Array(n); dp.fill(0);
    dp[0] = jobs[0][2];
    for (let i = 1; i < n; i++) {
        let l = 0, r = i - 1;
        while (l < r) {
            let mid = (l + r) >> 1;
            if (jobs[mid+1][1] <= jobs[i][0]) {
                l = mid + 1
            } else r = mid;
        }
        if (jobs[l][1] <= jobs[i][0]) {
            dp[i] = Math.max(dp[i - 1], dp[l] + jobs[i][2]);
        } else {
            dp[i] = Math.max(dp[i - 1], jobs[i][2]);
        }
    }
    return dp[n - 1];
};