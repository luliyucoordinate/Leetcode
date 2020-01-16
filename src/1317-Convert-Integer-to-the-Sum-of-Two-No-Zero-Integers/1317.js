var getNoZeroIntegers = function(n) {
    for (let a = 1; a < n; a++) {
        let b = n - a;
        if ((b+"").indexOf("0") == -1 && (a+"").indexOf("0") == -1) {
            return [a, b];
        }
    }
    return [];
};