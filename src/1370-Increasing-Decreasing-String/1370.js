var sortString = function(s) {
    let cnt = new Array(26).fill(0);
    for (let c of s) cnt[c.charCodeAt() - 97]++;
    
    let res = "";
    while (res.length < s.length) {
        for (let i = 0; i < 26; i++) {
            if (cnt[i] > 0) {
                res += String.fromCharCode(i + 97);
                cnt[i]--;
            }
        }
        
        for (let i = 25; i >= 0; i--) {
            if (cnt[i] > 0) {
                res += String.fromCharCode(i + 97);
                cnt[i]--;
            }
        }
    }
    return res;
};