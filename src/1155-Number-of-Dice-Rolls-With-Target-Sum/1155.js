var numRollsToTarget = function(d, f, target) {
    var mem = Array(target + 1);
    mem.fill(0); mem[0] = 1;
    for (var i = 0; i < d; ++i) {
        var tmp = Array(target + 1);
        tmp.fill(0);
        for (var j = 1; j <= f; ++j) {
            for (var k = j; k <= target; ++k) {
                tmp[k] = (tmp[k] + mem[k - j]) % 1000000007;
            }
        }
        mem = tmp;
    }
    return mem[target];
};