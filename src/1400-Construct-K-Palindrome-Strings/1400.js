var canConstruct = function(s, k) {
    let odds = 0, n = s.length, count = new Array(26).fill(0);
    for (let i = 0; i < n; ++i) {
        count[s.charCodeAt(i) - 97] ^= 1;
        odds += count[s.charCodeAt(i) - 97] > 0 ? 1 : -1;
    }
    return odds <= k && k <= n;
};