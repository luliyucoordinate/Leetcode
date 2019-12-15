/**
 * @param {number[]} arr
 * @return {number}
 */
var findSpecialInteger = function(arr) {
    let n = arr.length;
    var bs = (flag, t) => {
        let l = 0, r = n;
        while (l < r) {
            let mid = (l + r) >> 1;
            if (t < arr[mid] || (flag && t == arr[mid])) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }
    
    for (let i = 0; i < n; i += Math.floor(n / 4) + 1) {
        let l = bs(true, arr[i]), r = bs(false, arr[i]);
        if (r - l > n / 4) return arr[i];
    }
    return -1;
};