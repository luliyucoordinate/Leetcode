var kConcatenationMaxSum = function(arr, k) {
    var mod = 1e9 + 7, cur = 0, res = 0, total = 0;
    for (let num of arr) total += num;
    
    for (var i = 0; i < arr.length*Math.min(k, 2); ++i) {
        cur = Math.max(cur, 0) + arr[i%arr.length];
        res = Math.max(res, cur);
    }
    return Math.max(0, res, ((k-2)*total + res)%mod);
};