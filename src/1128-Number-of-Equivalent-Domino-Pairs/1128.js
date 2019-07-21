var numEquivDominoPairs = function(dominoes) {
    var cnt = Array(100), res = 0;
    cnt.fill(0);
    for (let d of dominoes) {
        res += cnt[Math.min(d[0], d[1])*10 + Math.max(d[0], d[1])]++;
    }
    return res;
};