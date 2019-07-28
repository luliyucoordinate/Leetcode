var isArmstrong = function(N) {
    var str = N.toString();
    var res = 0, n = str.length;
    for (let c of str) {
        res += Math.pow(parseInt(c), n);
    }
    return res == N;
};