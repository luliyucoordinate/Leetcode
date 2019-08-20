var maxDistance = function(grid) {
    var data = [];
    var r = grid.length, c = grid[0].length;
    for (var i = 0; i < r; ++i) {
        for (var j = 0; j < c; ++j) {
            if (grid[i][j]) data.push([i, j]);
        }
    }
    
    if (r*c == data.length || 0 == data.length) return -1;
    var d = [[0,1], [0,-1], [1,0], [-1,0]], res = 0;
    while (data.length > 0) {
        var dataLen = data.length;
        for (var i = 0; i < dataLen; ++i) {
            var pre = data.shift();
            for (let [xd, yd] of d) {
                var x = pre[0] + xd, y = pre[1] + yd;
                if (x >= 0 && x < r && y >= 0 && y < c && grid[x][y] == 0) {
                    grid[x][y] = 1;
                    data.push([x, y]);
                }
            }
        }
        res++;
    }
    return res - 1;
};