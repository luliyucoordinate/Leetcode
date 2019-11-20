/**
 * @param {character[][]} grid
 * @return {number}
 */
var minPushBox = function(grid) {
    let r = grid.length, c = grid[0].length;
    let B = [], S = [], T = [];
    let dire = [[0, 1], [0, -1], [-1, 0], [1, 0]];
    for (let i = 0; i < r; i++) {
        for (let j = 0; j < c; j++) {
            if (grid[i][j] == 'T') T = [i, j];
            else if (grid[i][j] == 'B') B = [i, j];
            else if (grid[i][j] == 'S') S = [i, j];
        }
    }

    let check = function(x, y) {
        return x >= 0 && x < r && y >= 0 && y < c && grid[x][y] != '#';
    }

    let canMoveTo = function(e, b, s) {
        let q = [s];
        let vis = new Array(21);
        for (let i = 0; i < 21; i++) {
            vis[i] = new Array(21).fill(0);
        }
        while (q.length) {
            let pre = q.shift();
            if (pre[0] == e[0] && pre[1] == e[1]) return true;
            for (let it of dire) {
                let nx = pre[0] + it[0], ny = pre[1] + it[1];
                if (check(nx, ny, grid) && 
                    (nx != b[0] || ny != b[1]) && !vis[nx][ny])
                {
                    q.push([nx, ny]);
                    vis[nx][ny] = 1;
                }
            }
        }
        return false;
    }

    let res = 0, q = [[B[0], B[1], S[0], S[1]]];
    let vis = new Array(21);
    for (let i = 0; i < 21; i++) {
        vis[i] = new Array(21);
        for (let j = 0; j < 21; j++) {
            vis[i][j] = new Array(21);
            for (let k = 0; k < 21; k++) {
                vis[i][j][k] = new Array(21).fill(0);
            }
        }
    }
    vis[B[0]][B[1]][S[0]][S[1]] = 1;
    while (q.length) {
        let n = q.length;
        while (n--) {
            let p = q.shift(); 
            if (p[0] == T[0] && p[1] == T[1]) return res;

            for (let it of dire)
            {
                let nx = it[0] + p[0], ny = it[1] + p[1];
                let e = [p[0] - it[0], p[1] - it[1]], b = [p[0], p[1]], s = [p[2], p[3]];
                if (check(nx, ny, grid) && check(e[0], e[1], grid) &&
                    !vis[nx][ny][p[0]][p[1]] && canMoveTo(e, b, s, grid))
                {
                    q.push([nx, ny, p[0], p[1]]);
                    vis[nx][ny][p[0]][p[1]] = 1;
                }
            }
        }
        res++;
    }
    return -1;
};