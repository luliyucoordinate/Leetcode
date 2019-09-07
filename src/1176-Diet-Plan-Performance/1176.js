var dietPlanPerformance = function(calories, k, lower, upper) {
    var cnt = 0;
    for (var i = 0; i < k; ++i) {
        cnt += calories[i];
    }
    var res = (cnt > upper) - (cnt < lower);
    for (var i = k; i < calories.length; ++i) {
        cnt += calories[i] - calories[i - k];
        res += (cnt > upper) - (cnt < lower);
    }
    return res;
};