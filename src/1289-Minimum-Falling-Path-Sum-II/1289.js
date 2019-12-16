var minFallingPathSum = function(A) {
    let r = A.length, c = A[0].length;
    for (let i = r - 1; i > 0; i--) {
        let m1 = [20000, 0], m2 = [20000, 0];
        for (let k = 0; k < c; k++) {
            if (A[i][k] < m1[0]) {
                m2 = m1.slice();
                m1 = [A[i][k], k];
            } else if (A[i][k] < m2[0]) {
                m2 = [A[i][k], k];
            }
        }
        
        for (let j = 0; j < c; j++) {
            A[i-1][j] += (j != m1[1] ? m1[0] : m2[0]);
        }
    }
    
    let res = 20000;
    for (let i = 0; i < c; i++) {
        res = Math.min(res, A[0][i]);
    }
    return res;
};