var equalSubstring = function(s, t, maxCost) {
    var d = [], l = 0, r = 0;
    for (var i = 0; i < s.length; i++) d.push(Math.abs(s[i].charCodeAt() - t[i].charCodeAt()));
    for (;r < s.length; r++) {
        maxCost -= d[r];
        if (maxCost < 0) {
            maxCost += d[l++];
        }
    }
    return r - l;
};