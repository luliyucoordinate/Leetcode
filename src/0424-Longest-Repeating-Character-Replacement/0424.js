var characterReplacement = function(s, k) {
    var res = 0, l = 0, n = s.length, mf = 0;
    var d = Array(26);
    d.fill(0);
    for (var r = 0; r < n; ++r) {
        mf = Math.max(mf, ++d[s[r].charCodeAt() - 65]);
        while (r - l + 1 - mf > k) {
            d[s[l].charCodeAt() - 65]--; l++;
        }
        res = Math.max(res, r - l + 1);
    }
    return res;
};