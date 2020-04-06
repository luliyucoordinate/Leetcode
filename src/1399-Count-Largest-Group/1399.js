var countLargestGroup = function(n) {
    let cnt = Array(37).fill(0), mx = 0;

    for (let i = 1; i <= n; ++i) {
        let c = 0, x = i;
        while (x > 0) {
            c += x % 10;
            x = Math.floor(x / 10);
        }
        cnt[c]++;
        mx = Math.max(mx, cnt[c]);
    }

    let res = 0;
    for (let i of cnt) {
        if (i == mx) res++;
    }
    return res;
};