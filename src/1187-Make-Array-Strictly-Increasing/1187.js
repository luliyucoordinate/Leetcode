//注意不要使用对象类型，因为对象属性是当成字符串处理的，所以采用加法会出问题
var makeArrayIncreasing = function(arr1, arr2) {
    var l1 = arr1.length, l2 = arr2.length;
    arr2.sort((a, b) =>  a - b);
    var dp = new Map([[0, arr1[0]], [1, arr2[0]]]);
    for (var i = 1; i < l1; i++) {
        var ndp = new Map();
        for (let [k, v] of dp) {
            if (arr1[i] > v && (!ndp.has(k) || ndp.get(k) > arr1[i])) ndp.set(k, arr1[i]);
            var l = 0, r = l2 - 1;
            while (l < r) {
                var mid = (l + r) >> 1;
                if (arr2[mid] <= v) l = mid + 1;
                else r = mid;
            }
            if (l < l2 && arr2[l] <= v) l++;
            if (l < l2 && (!ndp.has(k + 1) || ndp.get(k + 1) > arr2[l])) ndp.set(k+1, arr2[l]); // Object error
        }
        dp = ndp;
    }
    if (dp.size == 0) return -1;
    var res = 2000;
    for (let k of dp.keys()) res = Math.min(res, k);
    return res;
};