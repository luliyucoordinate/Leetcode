var minSteps = function(s, t) {
    let cnt = new Array(26), n = s.length, res = 0;
    cnt.fill(0);
    
    for (let i = 0; i < n; i++) {
        ++cnt[s[i].charCodeAt() - 97];
        --cnt[t[i].charCodeAt() - 97];
    }
    
    for (let i = 0; i < 26; i++) {
        if (cnt[i] > 0) res += cnt[i];
    }
    return res;
};