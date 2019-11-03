var numFriendRequests = function(ages) {
    let cnt = new Array(121), pre = new Array(121);
    cnt.fill(0), pre.fill(0);
    for (let a of ages) cnt[a]++;
    for (let i = 1; i < 121; i++) pre[i] = pre[i-1] + cnt[i];
    let res = 0;
    for (let i = 15; i < 121; i++)
        res += (pre[i] - pre[Math.floor(i/2) + 7] - 1)*cnt[i];
    return res;
};