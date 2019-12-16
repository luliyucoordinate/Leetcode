var sequentialDigits = function(low, high) {
    let res = [];
    for (let i = 1; i < 9; i++) {
        let x = i;
        while (x <= high) {
            let r = x % 10;
            if (r == 0) break;
            if (x >= low) res.push(x);
            x = x * 10 + r + 1;
        }
    }
    res.sort((a, b) => a - b);
    return res;
};