var checkIfCanBreak = function(s1, s2) {
    let d1 = new Array(26).fill(0), d2 = new Array(26).fill(0);
    for (let c of s1) d1[c.charCodeAt() - 97]++;
    for (let c of s2) d2[c.charCodeAt() - 97]++;
    
    let check = function(a1, a2) {
        let s = 0;
        for (let i = 0; i < 26; i++) {
            s += a1[i] - a2[i];
            if (s < 0) return false;
        }
        return true;
    }
    return check(d1, d2) || check(d2, d1);
};