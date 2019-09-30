var removeDuplicates = function(S) {
    let res = [];
    for (let c of S) {
        if (res.length > 0 && c == res[res.length - 1]) res.pop();
        else res.push(c);
    }
    return res.join('');
};