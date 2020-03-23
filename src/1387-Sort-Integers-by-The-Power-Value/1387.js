var getKth = function(lo, hi, k) {
    let res = [];
    for (let i = lo; i <= hi; i++) res[i - lo] = i;
    
    let cal = function(x) {
        let res = 0;
        while (x != 1) {
            if (x % 2 == 1) x = x * 3 + 1;
            else x >>= 1;
            res++;
        }
        return res;
    }
    
    res.sort((a, b) => {
        let p1 = cal(a), p2 = cal(b);
        return p1 == p2 ? a - b : p1 - p2;
    })
    return res[k - 1];
};