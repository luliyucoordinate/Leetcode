var toHexspeak = function(num) {
    let data = Number(num).toString(16).toUpperCase(), res = "";
    for (let i of data) {
        if (i > '1' && i <= '9') return "ERROR";
        if (i == '0') res += 'O';
        else if (i == '1') res += 'I';
        else res += i;
    }
    return res;
};