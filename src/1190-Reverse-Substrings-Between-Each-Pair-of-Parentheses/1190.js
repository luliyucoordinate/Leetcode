var reverseParentheses = function(s) {
    var pa = {}, st = [], t = 0;
    for (var i = 0; i < s.length; ++i) {
        if (s[i] == '(') st[t++] = i;
        if (s[i] == ')') {
            var j = st[--t];
            pa[i] = j, pa[j] = i;
        }
    }
    
    var res = "", i = 0, d = 1;
    while (i < s.length) {
        if (s[i] == ')' || s[i] == '(') {
            i = pa[i], d = -d;
        } else res += s[i];
        i += d;
    }
    return res;
};