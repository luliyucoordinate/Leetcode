var maxSideLength = function(A, t) {
    let r = A.length, c = A[0].length;
    let pre = new Array(r + 1);
    for (let i = 0; i <= r; i++) {
        pre[i] = new Array(c + 1);
        pre[i].fill(0);
    }
    for (let i = 1; i <= r; i++) {
        for (let j = 1; j <= c; j++) {
            pre[i][j] = pre[i-1][j] + pre[i][j-1] - pre[i-1][j-1] + A[i-1][j-1];
        }
    }

    let res = 0, l = 0;
    for (let i = 0; i <= r; i++) {
        for (let j = 0; j <= c; j++) {
            while (i + l <= r && j + l <= c &&
                  (pre[i+l][j+l]-pre[i+l][j]-pre[i][j+l]+pre[i][j] <= t)) {
                res = l++;
            }
        }
    }
    return res;
};