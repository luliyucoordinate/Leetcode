var getHappyString = function(n, k) {
    let prem = 1 << (n - 1);
    if (k > 3 * prem) return "";

    k--;
    let s = String.fromCharCode(97 + Math.floor(k / prem));
    while (prem > 1) {
        k %= prem;
        prem >>= 1;
        s += Math.floor(k / prem) == 0 ? s.charAt(s.length - 1) == 'a' ? 'b' : 'a' :
                                            s.charAt(s.length - 1) != 'c' ? 'c' : 'b';
    }
    return s;
};