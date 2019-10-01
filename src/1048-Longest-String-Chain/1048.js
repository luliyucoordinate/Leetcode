var longestStrChain = function(words) {
    let isPreString = function(s1, s2) {
        let p = 0, n = s1.length;
        for (let i = 0; i < n; i++) {
            if (s1[i] != s2[i + p]) {
                if (++p != 1) return false;
                else --i;
            }
        }
        return true;
    }
    
    let mem = new Array(17), res = 1;
    for (let i = 0; i <= 16; i++) mem[i] = [];
    for (let w of words) {
        mem[w.length].push([w, 1]);
    }
    for (let i = 2; i <= 16; i++) {
        for (let s2 of mem[i]) {
            for (let s1 of mem[i-1]) {
                if (isPreString(s1[0], s2[0])) {
                    s2[1] = Math.max(s2[1], s1[1] + 1);
                } 
                res = Math.max(res, s2[1]);
            }
        }
    }
    return res;
};