var maxStudents = function(seats) {
    let r = seats.length, c = seats[0].length;
    let d = [[-1, -1], [0, -1], [1, -1], [-1, 1], [0, 1], [1, 1]];
    let match = new Array(r * c);
    let res = 0, cnt = 0;
    let vis = new Array(r * c);

    let find = function(node, seats) {
        for (let it of d) {
            let nx = it[0] + node[0], ny = it[1] + node[1];
            if (nx >= 0 && nx < r && ny >= 0&& ny < c && vis[nx * c + ny] == 0 && seats[nx][ny] == '.') {
                vis[nx * c + ny] = 1;
                if (match[nx * c + ny] == null || find(match[nx * c + ny], seats)) {
                    match[nx * c + ny] = node;
                    return true;
                }
            }
        }
        return false;
    }
    
    for (let i = 0; i < r; i++) {
        for (let j = 0; j < c; j += 2) {
            if (seats[i][j] != '.') continue;
            vis.fill(0);
            let node = [i, j];
            if (find(node, seats)) res++;
        }
    }

    for (let i = 0; i < r; i++) {
        for (let j = 0; j < c; j++){
            if (seats[i][j] == '.') cnt++;
        }
    }
    return cnt - res;
};