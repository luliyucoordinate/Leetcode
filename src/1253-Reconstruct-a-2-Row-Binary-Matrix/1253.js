var reconstructMatrix = function(u, l, cs) {
    let res = new Array(2);
    for (let i = 0; i < 2; i++) {
        res[i] = new Array(cs.length);
        res[i].fill(0);
    }
    for (let i = 0; i < cs.length; i++) {
        res[0][i] = cs[i] == 2 || (cs[i] == 1 && l < u);
        res[1][i] = cs[i] == 2 || (cs[i] == 1 && !res[0][i]);
        u -= res[0][i] ? 1 : 0;
        l -= res[1][i] ? 1 : 0;
    }
    return l == 0 && u == 0 ? res : [];
};