/**
 * @param {number[][]} mat
 * @return {number}
 */
var minFlips = function(mat) {
    let start = 0, r = mat.length, c = mat[0].length;
    let d = [0, 0, 1, 0, -1, 0];
    for (let i = 0; i < r; i++) {
        for (let j = 0; j < c; j++) {
            start |= mat[i][j] << i * c + j;
        }
    }

    let q = [start], seen = new Map();
    for (let step = 0; q.length > 0; step++) {
        for (let qs = q.length; qs > 0; qs--) {
            let cur = q.shift();
            if (cur == 0) return step;
            for (let i = 0; i < r; i++) {
                for (let j = 0; j < c; j++) {
                    let ne = cur;
                    for (let k = 0; k < 5; k++) {
                        let x = d[k] + i, y = d[k + 1] + j;
                        if (x >= 0 && x < r && y >= 0 && y < c) {
                            ne ^= 1 << x * c + y;
                        }
                    }
                    if (!seen.has(ne)) {
                        seen.set(ne, 1);
                        q.push(ne);
                    }
                }
            }
        }
    }
    return -1;
};