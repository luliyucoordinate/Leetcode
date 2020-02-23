var numberOfSubstrings = function(s) {
    let cnt = [0, 0, 0], res = 0, l = 0, n = s.length;
    
    for (let r = 0; r < n; ++r) {
        ++cnt[s.charCodeAt(r) - 97];
        while (cnt[0] > 0 && cnt[1] > 0 && cnt[2] > 0) {
            res += n - r;
            --cnt[s.charCodeAt(l++) - 97];
        }
    }
    return res;
};