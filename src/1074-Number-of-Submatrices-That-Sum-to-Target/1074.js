var numSubmatrixSumTarget = function(A, target) {
    let r = A.length, c = A[0].length;
    for (let row of A) {
        for (let i = 1; i < c; i++) row[i] += row[i - 1];
    }

    let res = 0, cur = 0;
    let cnt = new Map();
    for (let i = 0; i < c; i++) {
        for (let j = i; j < c; j++) {
            cnt.clear();
            cnt.set(0, 1);
            cur = 0;
            for (let k = 0; k < r; k++) {
                cur += A[k][j] - (i > 0 ? A[k][i - 1] : 0);
                res += cnt.get(cur - target) || 0;
                cnt.set(cur, (cnt.get(cur) || 0) + 1);
            }
        }
    }
    return res; 
};