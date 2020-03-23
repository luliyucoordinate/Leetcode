var findTheDistanceValue = function(arr1, arr2, d) {
    arr2.sort((a, b) => a - b);
    
    let check = function(x) {
        let l = 0, r = arr2.length - 1;
        while (l < r) {
            let mid = (l + r) >> 1;
            if (Math.abs(arr2[mid] - x) <= d) return false;
            if (arr2[mid] > x) r = mid;
            else l = mid + 1;
        }
        return Math.abs(arr2[l] - x) > d;
    }
    
    let res = 0;
    for (let x of arr1) {
        if (check(x)) res++;
    }
    return res;
};