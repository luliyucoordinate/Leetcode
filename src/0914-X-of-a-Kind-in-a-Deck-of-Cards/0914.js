var hasGroupsSizeX = function(deck) {
    let gcd = function(a, b) {
        return b == 0 ? a : gcd(b, a % b);
    }

    let cnt = new Array(10000).fill(0);
    for (let d of deck) cnt[d]++;

    let res = -1;
    for (let i = 0; i < 10000; i++) {
        if (cnt[i] > 0) {
            if (res == -1) res = cnt[i];
            else res = gcd(res, cnt[i]);
        }
    }
    return res >= 2;
};