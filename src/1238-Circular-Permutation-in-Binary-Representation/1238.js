var circularPermutation = function(n, start) {
    let res = [];
    for (let i = 0; i < (1 << n); i++) res.push(start^i^(i >> 1));
    return res;
};