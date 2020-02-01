/**
 * @param {number} n
 * @param {number[][]} edges
 * @param {number} distanceThreshold
 * @return {number}
 */
var findTheCity = function(n, edges, distanceThreshold) {
    let d = new Array(n);
    for (let i = 0; i < n; i++) {
        d[i] = new Array(n);
        for (let j = 0; j < n; j++) {
            if (i == j) d[i][i] = 0;
            else d[i][j] = 10010;
        }
    }

    for (let it of edges) {
        d[it[0]][it[1]] = d[it[1]][it[0]] = it[2];
    }

    for (let k = 0; k < n; k++) {
        for (let i = 0; i < n; i++) {
            for (let j = 0; j < n; j++) {
                d[i][j] = Math.min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }

    let smallest = 10010, res = 0;
    for (let i = 0; i < n; i++) {
        let cnt = 0;
        for (let j = 0; j < n; j++) {
            if (d[i][j] <= distanceThreshold) ++cnt;
        }
        if (cnt <= smallest) {
            res = i;
            smallest = cnt;
        }
    }
    return res;
};