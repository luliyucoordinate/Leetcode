var printVertically = function(s) {
    let strs = s.split(" "), max_len = 0;
    for (let st of strs) {
        max_len = Math.max(max_len, st.length);
    }
    
    let res = [];
    for (let j = 0; j < max_len; j++) {
        let t = "", t_len = 0;
        for (let st of strs) {
            if (st.length > j) {
                t += st[j];
                t_len = t.length;
            } else t += " ";
        }
        res.push(t.substring(0, t_len));
    }
    return res;
};