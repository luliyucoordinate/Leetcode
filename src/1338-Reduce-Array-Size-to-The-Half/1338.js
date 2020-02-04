var minSetSize = function(arr) {
    let n = Math.floor(arr.length / 2), total = 0, res = 0;
    let freq = new Map(), cnt = new Map();
    for (let i of arr) freq.set(i, (freq.get(i) || 0) + 1);
    for (let v of freq.values()) cnt.set(v, (cnt.get(v) || 0) + 1);
    
    let cnt_keys = [...cnt.keys()];
    cnt_keys.sort((a, b) => b - a);
    for (let i of cnt_keys) {
        let dif = n - total;
        let x = Math.min(cnt.get(i), Math.ceil(dif/i));
        res += x;
        total += x * i;
        if (total >= n) return res;
    }
    return res;
};