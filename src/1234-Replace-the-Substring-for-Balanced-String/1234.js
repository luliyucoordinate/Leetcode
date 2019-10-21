var balancedString = function(s) {
    let cnt = new Array(128);
    cnt.fill(0);
    for (let c of s) cnt[c.charCodeAt()]++;
    
    let n = s.length, res = n;
    let i = 0, avg = Math.floor(n/4);
    for (let j = 0; j < n; j++) {
        cnt[s[j].charCodeAt()]--;
        while (i < n && cnt['Q'.charCodeAt()] <= avg && 
                   cnt['W'.charCodeAt()] <= avg && 
                   cnt['E'.charCodeAt()] <= avg && 
                   cnt['R'.charCodeAt()] <= avg)
            {
                res = Math.min(res, j - i + 1);
                cnt[s[i++].charCodeAt()]++;
            }
    }
    return res;
};