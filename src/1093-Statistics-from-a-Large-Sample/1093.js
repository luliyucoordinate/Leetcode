var sampleStats = function(count) {
    var res = [255, 0, 0, 0, 0];
    var sum_all = count.reduce(function(pre, cur) {
        return pre + cur;
    }, 0);
    
    var l = sum_all / 2, r = l + (sum_all & 1 ? 0 : 1), m_cnt = 0;
    for (var i = 0, cnt = 0; i < count.length; cnt += count[i++]) {
        res[0] = count[i] ? Math.min(res[0], i) : res[0];
        res[1] = count[i] ? i : res[1];
        res[2] += i * count[i] / sum_all;
        if (cnt < l && cnt + count[i] >= l) res[3] += i / 2;
        if (cnt < r && cnt + count[i] >= r) res[3] += i / 2;   
        if (m_cnt < count[i]) {
            m_cnt = count[i];
            res[4] = i;
        }
    }
    return res;
};