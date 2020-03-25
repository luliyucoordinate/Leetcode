var longestPrefix = function(s) {
    let n = s.length, i = 0, j;
    let f = new Array(n + 1).fill(0);
    f[0] = j = -1;

    while (i < n) {
        while (j != -1 && s.charAt(i) != s.charAt(j)) j = f[j];
        ++i; ++j;
        f[i] = j;
    }
    return s.substring(0, f[n]);
};