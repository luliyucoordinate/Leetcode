var shortestPathBinaryMatrix = function(grid) {
    if (grid.length == 0) return -1;
    
    var r = grid.length, c = grid[0].length;
    if (grid[r-1][c-1] == 1 || grid[0][0] == 1) return -1;
    
    var dire = [[1, 0], [-1, 0], [0, -1], [0, 1], [1, 1], [1, -1], [-1, 1], [-1, -1]];
    var q = [[0, 0, 1]];
    while (q.length) {
        var pre = q.shift();
        if (pre[0] == r-1 && pre[1] == c-1) return pre[2];
        for (var i = 0; i < 8; ++i) {
            var nx = dire[i][0] + pre[0], ny = dire[i][1] + pre[1];
            if (nx >= 0 && nx < r && ny >= 0 && ny < c && grid[nx][ny] == 0) {
                grid[nx][ny] = 1;
                q.push([nx, ny, pre[2] + 1]);
            }
        }
    }
    return -1;
};