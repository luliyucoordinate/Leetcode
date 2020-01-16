var minFlips = function(a, b, c) {
    let res = 0;
    while (a || b || c) {
        if (c & 1) res += (a & 1) || (b & 1) ? 0 : 1;
        else res += (a & 1) + (b & 1);
        a >>= 1, b >>= 1, c >>= 1;
    }
    return res;
};