/**
 * @param {number[][]} grid
 * @param {number} k
 * @return {number}
 */
var shortestPath = function(g, k) {
    let r = g.length, c = g[0].length, step = 0;
    if (k >= r + c - 3) return r + c - 2;

    let mem = new Array(r);
    for (let i = 0; i < r; i++) {
        mem[i] = new Array(c);
        mem[i].fill(10000);
    }

    let q = [[0,0,0]], d = [0, 1, 0, -1, 0];
    mem[0][0] = 0;

    while (q.length != 0) {
        for (let n = q.length; n > 0; n--) {
            let pre = q.shift();
            if (pre[2] > k) continue;
            if (pre[0] == r - 1 && pre[1] == c - 1) return step;

            for (let i = 0; i < 4; i++) {
                let nx = pre[0] + d[i], ny = pre[1] + d[i+1];
                if (nx >= 0 && nx < r && ny >= 0 && ny < c) {
                    let nPre = g[nx][ny] == 1 ? pre[2] + 1 : pre[2];
                    if (nPre < mem[nx][ny]) {
                        q.push([nx, ny, nPre]);
                        mem[nx][ny] = nPre;
                    }
                }
            }
        }
        step++;
    }
    return -1;
};