var freqAlphabets = function(s) {
    let res = "";
    for (let i = 0; i < s.length; i++) {
        if (i + 2 < s.length && s[i + 2] == '#') {
            res += String.fromCharCode((Number(s.substring(i, i + 2)) + 96));
            i += 2;
        }else res += String.fromCharCode(s.charCodeAt(i) + 48);
    }
    return res;
};