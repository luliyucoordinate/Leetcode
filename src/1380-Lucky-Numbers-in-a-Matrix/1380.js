var luckyNumbers  = function(A) {
    let r = A.length, c = A[0].length, res = [];

    for (let i = 0; i < r; i++) {
        let minv = 100000, minp = -1;
        for (let j = 0; j < c; j++) {
            if (A[i][j] < minv) {
                minv = A[i][j];
                minp = j;
            }
        }

        let flag = false;
        for (let j = 0; j < r; j++) {
            if (A[j][minp] > minv) {
                flag = true;
                break;
            }
        }
        if (!flag) res.push(minv);
    }
    return res;
};