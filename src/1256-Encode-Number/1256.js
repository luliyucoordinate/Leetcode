var encode = function(num) {
    let res = "";
    num++;
    while (num) {
        res = (num & 1 ? "1" : "0") + res;
        num >>= 1;
    }
    return res.substring(1);
};