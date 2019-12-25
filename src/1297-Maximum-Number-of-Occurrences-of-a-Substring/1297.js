var maxFreq = function(s, maxLetters, minSize, maxSize) {
    let chs = new Array(256);
    chs.fill(0);
    let nq = res = 0, l = minSize, cnt = new Map();
    
    for (let r = 0; r < s.length; r++) {
        if (chs[s.charCodeAt(r)]++ == 0) ++nq;
        if (l <= r) {
            if (--chs[s.charCodeAt(r - l)] == 0) --nq;
        }
        
        if (l - 1 <= r && nq <= maxLetters) {
            let curStr = s.substring(r - l + 1, r + 1);
            let t = (cnt.get(curStr) || 0) + 1;
            cnt.set(curStr, t);
            if (t > res) res = t;
        }
    }
    return res;
};