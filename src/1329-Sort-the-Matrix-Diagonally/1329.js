var diagonalSort = function(mat) {
    let r = mat.length, c = mat[0].length;
    for (let i = 0; i < r; i++) {
        let k = Math.min(r - i, c), t = [];
        for (let j = 0; j < k; j++) t.push(mat[i + j][j]);
        t.sort((a, b) => a - b);
        for (let j = 0; j < k; j++) mat[i + j][j] = t[j];
    }
    
    for (let i = 1; i < c; i++) {
        let k = Math.min(c - i, r), t = [];
        for (let j = 0; j < k; j++) t.push(mat[j][i + j]);
        t.sort((a, b) => a - b);
        for (let j = 0; j < k; j++) mat[j][i + j] = t[j];
    }
    return mat;
};  