var movesToStamp = function(stamp, target) {
    let s_len = stamp.length, t_len = target.length, t = target.split('');
    let check = function(k) {
        let ret = false;
        for (let i = 0; i < s_len; i++) {
            if (t[k + i] != '?') {
                if (t[k + i] != stamp[i]) return false;
                ret = true;
            }
        }
        return ret;
    }
    let compareArray = function(a, b) {
        for (let i = 0; i < t_len; i++) {
            if (a[i] != b[i]) return false;
        }
        return true;
    }
    let done = new Array(t_len);
    done.fill('?');
    let res = [];
    while (!compareArray(done, t)) {
        let move = false;
        for (let i = 0; i < t_len - s_len + 1; i++) {
            if (check(i)) {
                move = true;
                res.unshift(i);
                for (let j = i; j < i + s_len; j++) t[j] = '?';
            }
        }
        if (!move) return [];
    }
    return res;
};