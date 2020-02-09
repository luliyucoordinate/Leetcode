var numOfSubarrays = function(arr, k, threshold) {
    let s = 0, res = 0, t = k * threshold, n = arr.length;
    for (let i = 0; i < k - 1; i++) s += arr[i];
    
    for (let l = 0; l < n - k + 1; l++) {
        s += arr[l + k - 1];
        if (s >= t) ++res;
        s -= arr[l];
    }
    return res;
};