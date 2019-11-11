var oddCells = function(n, m, indices) {
    let row = Array(n), col = Array(n);
    row.fill(0); col.fill(0);
    let rowCnt = 0, colCnt = 0;
    for (let it of indices) {
        row[it[0]] ^= 1;
        col[it[1]] ^= 1;
        rowCnt += row[it[0]] == 1 ? 1 : -1;
        colCnt += col[it[1]] == 1 ? 1 : -1;
    }
    return m * rowCnt + n * colCnt - rowCnt * colCnt * 2;
};