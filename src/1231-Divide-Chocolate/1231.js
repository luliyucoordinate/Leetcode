var maximizeSweetness = function(sweetness, K) {
    let s = 0;
    for (let v of sweetness) s += v;
    let l = 1, r = Math.floor(s/(K + 1));
    while (l < r) {
        let mid = (l + r + 1) >> 1;
        let cur = 0, cuts = 0;
        for (let v of sweetness) {
            cur += v;
            if (cur >= mid) {
                cuts++, cur = 0;
            }
        }
        if (cuts > K) l = mid;
        else r = mid - 1;
    }
    return l;
};