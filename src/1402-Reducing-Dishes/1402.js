var maxSatisfaction = function(s) {
    s.sort((a, b) => a - b);
    let res = 0, total = 0, n = s.length;

    for (let i = n - 1; i >= 0 && s[i] > -total; --i) {
        total += s[i];
        res += total;
    }
    return res;
};