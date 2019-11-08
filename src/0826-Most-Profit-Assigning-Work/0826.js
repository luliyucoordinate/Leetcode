var maxProfitAssignment = function(difficulty, profit, worker) {
    let jobs = [], N = profit.length, res = 0, i = 0, best = 0;
    for (let j = 0; j < N; j++) {
        jobs.push([difficulty[j], profit[j]]);
    }
    jobs.sort(function(a, b) {
        if (a[0] == b[0]) return a[1] - b[1];
        return a[0] - b[0];
    });
    
    worker.sort((a, b) => a - b);
    for (let w of worker) {
        while (i < N && w >= jobs[i][0]) {
            best = Math.max(best, jobs[i++][1]);
        }
        res += best;
    }
    return res;
};