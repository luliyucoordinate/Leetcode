var numKLenSubstrNoRepeats = function(S, K) {
    var res = 0, low = -1;
    var usedChar = {};
    for (var i = 0; i < S.length; ++i) {
        if (usedChar[S[i]] && usedChar[S[i]] >= low) low = usedChar[S[i]];
        if (i - low >= K) res++;
        usedChar[S[i]] = i;
    }
    return res;
}