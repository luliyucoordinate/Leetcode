var minimumMoves = function(arr) {
    let n = arr.length;
    let mem = new Array(n + 1);
    for (let i = 0; i <= n; i++) {
        mem[i] = new Array(n + 1);
        mem[i].fill(0);
    }
    for (let l = 1; l <= n; l++) {
        let i = 0, j = l - 1;
        while (j < n) {
            if (l == 1) mem[i][j] = 1;
            else {
                mem[i][j] = 1 + mem[i + 1][j];
                for (let k = i + 1; k <= j; k++) {
                    if (arr[k] == arr[i]) {
                        mem[i][j] = Math.min(mem[i][j], mem[i+1][k-1] + mem[k+1][j] + (i + 1 == k));
                    }
                }
            }
            ++i, ++j;
        }
    }
    return mem[0][n - 1];
};