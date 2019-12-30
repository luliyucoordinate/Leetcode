var sumZero = function(n) {
    let res = new Array(n);
    for (let i = 1 - n, j = 0; i < n; i += 2, j++) res[j] = i;
    return res;
};