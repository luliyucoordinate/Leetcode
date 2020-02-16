var countNegatives = function(grid) {
    let r = grid.length, c = grid[0].length;
    let res = 0, m = r - 1, n = 0;

    while (m >= 0 && n < c) {
        if (grid[m][n] < 0) {
            res += c - n;
            m--;
        } else n++;
    }
    return res;
};