var minimumAbsDifference = function(arr) {
    arr.sort(function(a, b) {
        return a - b;
    });
    var min_dif = 1e7, res = [];
    for (var i = 1; i < arr.length; i++) {
        var dif = arr[i] - arr[i-1];
        if (dif > min_dif) continue;
        else if (dif < min_dif) {
            min_dif = dif;
            res = [];
        }
        res.push([arr[i-1], arr[i]]);
    }
    return res;
};