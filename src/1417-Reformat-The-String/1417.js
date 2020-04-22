var reformat = function(s) {
    let digits = [], chars = [];
    for(let c of s) {
        if (c >= '0' && c <= '9') digits.push(c);
        else chars.push(c);
    }
    if (Math.abs(digits.length - chars.length) > 1) return "";

    let res = "";
    let flag = digits.length >= chars.length ? true : false; 
    for (let i = 0; i < s.length; i++){
        if (flag) res += digits.pop();
        else res += chars.pop();
        flag = !flag; 
    }
    return res; 
};