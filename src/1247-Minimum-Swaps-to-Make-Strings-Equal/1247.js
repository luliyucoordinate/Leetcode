var minimumSwap = function(s1, s2) {
    let x = 0, y = 0, n = s1.length;
    for (let i = 0; i < n; i++) {
        if (s1[i] != s2[i]) {
            if (s1[i] == 'x') x++;
            else y++;
        }
    }
    if ((x + y) & 1) return -1;
    return Math.floor(x / 2) + Math.floor(y / 2) + 2 * (x % 2);
};