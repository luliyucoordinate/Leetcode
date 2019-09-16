var maxNumberOfBalloons = function(text) {
    var cnt = {};
    for (let c of text) {
        cnt[c] = cnt[c] || 0;
        cnt[c]++;
    }
    return Math.min(cnt.b, cnt.a, cnt.l/2, cnt.o/2, cnt.n) | 0;
};