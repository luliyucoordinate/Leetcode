var numKLenSubstrNoRepeats = function(S, K) {
    var res = 0, low = -1;
    var usedChar = new Map();
    for (var i = 0; i < S.length; ++i) {
        if (usedChar.has(S[i]) && usedChar.get(S[i]) >= low) low = usedChar.get(S[i]);
        if (i - low >= K) res++;
        usedChar.set(S[i], i);
    }
    return res;
}