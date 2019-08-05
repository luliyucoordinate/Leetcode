var longestDecomposition = function(text) {
    var n = text.length;
    for (var i = 1; i <= n/2; ++i) {
        if (text.substr(0,i) == text.substr(n-i))
            return 2 + longestDecomposition(text.substr(i,n-2*i));
    }
    return n == 0 ? 0 : 1;
};