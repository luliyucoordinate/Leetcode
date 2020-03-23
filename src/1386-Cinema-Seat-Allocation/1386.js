var maxNumberOfFamilies = function(n, reservedSeats) {
    let cnt = new Map();
    for (let t of reservedSeats) {
        cnt.set(t[0], (cnt.get(t[0]) || 0) | 1 << (t[1] - 1));
    }

    let res = 0, q1 = parseInt(111111110, 2), q2 = parseInt(111100000, 2), q3 = parseInt(11110, 2), q4 = parseInt(1111000, 2);
    for (let v of cnt.values()) {
        if ((q1 & v) == 0) res += 2;
        else if ((q2 & v) == 0 || (q3 & v) == 0 || (q4 & v) == 0) res++;
    }
    return res + (n - cnt.size) * 2;
};