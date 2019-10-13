var queensAttacktheKing = function(queens, king) {
    let g = [];
    for (let i = 0; i < 8; i++) {
        g[i] = new Array(8);
        g[i].fill(0);
    }
    for (let i in queens) {
        g[queens[i][0]][queens[i][1]] = 1;
    }
    
    let res = [];
    for (let i = -1; i <= 1; i++) {
        for (let j = -1; j <= 1; j++) {
            for (let k = 1; k < 8; k++) {
                let x = king[0] + i*k, y = king[1] + j*k;
                if (x >= 0 && y >= 0 && x < 8 && y < 8 && g[x][y] == 1) {
                    res.push([x, y]);
                    break;
                }
            }
        }
    }
    return res;
};