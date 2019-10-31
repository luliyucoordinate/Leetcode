var calculate = function(s) {
    let st = [], op = 1, r = l = 0;
    for (let c of s) {
        if (c >= '0' && c <= '9') r = r * 10 + Number(c);
        else if (c == '+' || c == '-') {
            l += op * r;
            r = 0, op = c == '+' ? 1 : -1;
        } else if (c == '(') {
            st.push(l), st.push(op);
            op = 1, l = 0;
        } else if (c == ')') {
            l += op * r;
            r = 0;
            l = st.pop() * l + st.pop();
        }
    }
    return l + op * r;
};