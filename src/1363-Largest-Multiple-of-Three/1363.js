var largestMultipleOfThree = function(digits) {
    let cnt = Array(10).fill(0);
    for (let d of digits) cnt[d]++;
    let b1 = cnt[1] + cnt[4] + cnt[7], b2 = cnt[2] + cnt[5] + cnt[8]; 
    let t = (b1 + 2 * b2) % 3;
    if (t == 1) { 
        if (b1 >= 1) b1 -= 1;
        else b2 -= 2;
    } else if (t == 2) { 
        if (b2 >= 1) b2 -= 1;
        else b1 -= 2;
    }

    let res = "";
    for (let d = 9; d >= 0; d--) {
        if (d % 3 == 0) while (cnt[d]-- > 0) res += d;
        else if (d % 3 == 1) while (cnt[d]-- > 0 && b1-- > 0) res += d;
        else while (cnt[d]-- > 0 && b2-- > 0) res += d;
    }
    if (res.length && res.charAt(0) == '0') return "0"; 
    return res;
};