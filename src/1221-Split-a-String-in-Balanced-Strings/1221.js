var balancedStringSplit = function(s) {
    var res = L = 0;
    for (let c of s) {
        if (c == 'L') L++;
        else L--;
        if (L == 0) res++;
    }
    return res;
};