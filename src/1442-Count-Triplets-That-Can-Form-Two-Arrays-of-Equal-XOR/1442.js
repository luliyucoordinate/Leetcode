var countTriplets = function(arr) {
    let n = arr.length, res = 0, prefix = 0, c, t;
    let cnt = {}, total = {};
    cnt[0] = 1;

    for (let i = 0; i < n; i++) {
        prefix ^= arr[i];
        c = cnt[prefix] || 0;
        t = total[prefix] || 0;
        res += c * i - t;
        cnt[prefix] = c + 1;
        total[prefix] = t + i + 1;
    }
    return res;
};