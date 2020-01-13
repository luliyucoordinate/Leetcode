var matrixBlockSum = function(mat, K) {
    let r = mat.length, c = mat[0].length;
    let pre = new Array(r + 1);
    for (let i = 0; i <= r; i++) {
        pre[i] = new Array(c + 1);
        pre[i].fill(0);
    }
    
    for (let i = 0; i < r; i++) {
        for (let j = 0; j < c; j++) {
            pre[i + 1][j + 1] = pre[i + 1][j] + pre[i][j + 1] - pre[i][j] + mat[i][j];
        }
    }

    let res = new Array(r);
    for (let i = 0; i < r; i++) {
        res[i] = new Array(c);
        res[i].fill(0);
    }
    for (let i = 0; i < r; i++) {
        for (let j = 0; j < c; j++) {
            let r1 = Math.max(0, i - K), c1 = Math.max(0, j - K), r2 = Math.min(r, i + K + 1), c2 = Math.min(c, j + K + 1);
            res[i][j] = pre[r2][c2] - pre[r1][c2] - pre[r2][c1] + pre[r1][c1];
        }
    }
    return res;
};