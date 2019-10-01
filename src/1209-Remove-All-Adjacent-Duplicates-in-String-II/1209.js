var removeDuplicates = function(s, k) {
    var st = []; st.push(['#', 0]);
    for (let c of s) {
        if (c == st[st.length-1][0]) {
            st[st.length-1][1]++;
            if (st[st.length-1][1] == k) st.pop();
        } else st.push([c, 1]);
    }
    
    var res = "";
    for (let [k, v] of st) {
        res += k.repeat(v);
    }
    return res;
};