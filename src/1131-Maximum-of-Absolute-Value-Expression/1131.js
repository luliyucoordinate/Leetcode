var maxAbsValExpr = function(arr1, arr2) {
    var res = 0, n = arr1.length;
    var dire = [[1, 1], [1, -1], [-1, 1], [-1, -1]];
    for (let op of dire) {
        var r = arr1[0] * op[0] + arr2[0] * op[1];
        for (let i = 0; i < n; ++i) {
            l = arr1[i] * op[0] + arr2[i] * op[1] + i;
            res = Math.max(res, l - r);
            r = Math.min(l, r);
        }
    }
    return res;
};