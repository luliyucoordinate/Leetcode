var maximalSquare = function(matrix) {
    if (!matrix.length) return 0;
    let res = 0, r = matrix.length, c = matrix[0].length;
    let mem = new Array(r);
    for (let i = 0; i < r; ++i) {
        mem[i] = new Array(c);
        mem[i].fill(0);
    }
    for (let i = 0; i < r; ++i)
    {
        for (let j = 0; j < c; ++j)
        {
            if (!i || !j || matrix[i][j] == '0') mem[i][j] = Number(matrix[i][j]);
            else mem[i][j] = Math.min(Math.min(mem[i-1][j], mem[i][j-1]), mem[i-1][j-1]) + 1;
            res = Math.max(res, mem[i][j]);
        }
    }
    return res * res;
};