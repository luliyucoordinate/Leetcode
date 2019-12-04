var countSquares = function(A) {
    let res = 0;
    for (let i = 0; i < A.length; i++) {
        for (let j = 0; j < A[0].length; j++) {
            if (i > 0 && j > 0 && A[i][j] > 0)
                A[i][j] = Math.min(A[i - 1][j], Math.min(A[i][j - 1], A[i - 1][j - 1])) + 1;
            res += A[i][j];
        }
    }
    return res;
};