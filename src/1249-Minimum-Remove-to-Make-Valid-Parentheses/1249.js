var minRemoveToMakeValid = function(s) {
    let st = [];
    for (let i = 0; i < s.length; i++) {
        if (s[i] == ')') {
            if (st.length && s[st[st.length - 1]] == '(') {
                st.pop();
                continue;
            }
            st.push(i);
        } else if (s[i] == '(') st.push(i);
    }
    
    let res = "", pre = 0;
    for (let i = 0; i < st.length; i++) {
        res += s.substr(pre, st[i] - pre);
        pre = st[i] + 1;
    }
    res += s.substr(pre);
    return res;
};