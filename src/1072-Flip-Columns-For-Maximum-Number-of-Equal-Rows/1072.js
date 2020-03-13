var maxEqualRowsAfterFlips = function(matrix) {
    let m = new Map(), res = 0;
    
    for (let row of matrix) {
        let s = "";
        for (let r of row) s += (r ^ row[0]);
        m.set(s, (m.get(s) || 0) + 1);
        res = Math.max(res, m.get(s));
    }
    return res;
};