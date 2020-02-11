var maxRepOpt1 = function(s) {
    var res = 0, l = 0, n = s.length, mf = 0, mc = s[0];
    var d = Array(26).fill(0), cnt = Array(26).fill(0);
    for (let c of s) cnt[c.charCodeAt() - 97]++;

    for (var r = 0; r < n; ++r) {
        if (mf < ++d[s[r].charCodeAt() - 97]) {
            mf = d[s[r].charCodeAt() - 97];
            mc = s[r].charCodeAt() - 97;
        }

        if (r - l + 1 - mf > 1) {
            d[s[l].charCodeAt() - 97]--; l++;
        }
        res = Math.max(res, r - l + 1);
    }
    return Math.min(res, cnt[mc]);
};