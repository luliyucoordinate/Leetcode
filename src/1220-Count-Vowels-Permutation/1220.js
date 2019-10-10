var countVowelPermutation = function(n) {
    let mod = 1e9 + 7, a = 1, e = 1, i = 1, o = 1, u = 1;
    for (let k = 1; k < n; k++) {
        let ao = a; a = (e + i + u)%mod; 
        let eo = e; e = (ao + i)%mod;
        let io = i; i = (eo + o)%mod;
        let oo = o; o = io;
        u = (io + oo)%mod;
    }
    return (a + e + i + o + u)% mod;
};