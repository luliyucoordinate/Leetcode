var uniqueLetterString = function(S) {
    let res = 0, f = 0, mod = 1000000007;
    let m = new Array(26), n = new Array(26);
    m.fill(0), n.fill(0);
    for (let i = 0; i < S.length; i++) {
        let t = S.charCodeAt(i) - 65;
        f = f + 1 + i - 2* m[t] + n[t];
        res = (res + f) % mod;
        n[t] = m[t];
        m[t] = i + 1;
    }
    return res;
};