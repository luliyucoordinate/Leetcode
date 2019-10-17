var camelMatch = function(qs, pattern) {
    let res = [];
    for (let i = 0; i < qs.length; i++) {
        let j, p;
        for (j = 0, p = 0; j < qs[i].length; j++) {
            if (p < pattern.length && qs[i][j] == pattern[p]) ++p;
            else if ("A" <= qs[i][j] && qs[i][j] <= "Z") break;
        }
        res.push(j == qs[i].length && p == pattern.length);
    }
    return res;
};