var sortByBits = function(arr) {
    let bin = function(x) {
        let res = 0;
        while (x) {
            x = x & (x - 1);
            res++;
        }
        return res;
    }
    arr.sort((a, b) => (bin(a) * 10000 + a) - (bin(b) * 10000 + b));
    return arr;
};