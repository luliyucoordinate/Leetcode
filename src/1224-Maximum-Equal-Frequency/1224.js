var maxEqualFreq = function(nums) {
    let n = nums.length;
    let k = new Array(n + 1), res = 0, f = new Array(100005);
    k.fill(0), f.fill(0);
    for (let i = 1; i <= n; i++) {
        let a = nums[i - 1];
        k[f[a]]--, f[a]++, k[f[a]]++;
        let t = f[a];
        if (k[t] * t == i && i < n) res = i + 1;
        else {
            let d = i - k[t] * t;
            if ((d == 1 || d == t + 1) && k[d] == 1) res = i;
        }
    }
    return res;
};