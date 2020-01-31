var breakPalindrome = function(p) {
    let n = Math.floor(p.length/2);
    for (let i = 0; i < n; i++) {
        if (p[i] != 'a') {
            return p.slice(0, i) + 'a' + p.slice(i + 1);
        }
    }
    return p.length > 1 ? p.slice(0, p.length - 1) + 'b' : "";
};