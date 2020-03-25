/**********************************************
error: Maximum call stack size exceeded
************************************************
var hasValidPath = function(grid) {
    let r = grid.length; c = grid[0].length;
    let d = [[0, 1], [1, 0], [0, -1], [-1, 0]];
    let p = [[2, -1, 0, -1], 
            [-1, 3, -1, 1], 
            [-1, 2, 1, -1],
            [1, 0, -1, -1],
            [-1, -1, 3, 2],
            [3, -1, -1, 0]];
    
    let dfs = function(grid, x, y, di) {
        if (p[grid[x][y] - 1][di] == -1) return false;
        if (x == r - 1 && y == c - 1) return true;
        
        let dx = d[p[grid[x][y] - 1][di]][0], dy = d[p[grid[x][y] - 1][di]][1];
        let nx = x + dx, ny = y + dy;
        if (0 <= nx && nx < r && 0 <= ny && ny < c) {
            if (dfs(grid, nx, ny, (p[grid[x][y] - 1][di] + 2) % 4)) return true;
        }
        return false;
    }

    return dfs(grid, 0, 0, 0) || dfs(grid, 0, 0, 1) || dfs(grid, 0, 0, 2) || dfs(grid, 0, 0, 3);
};
*/

var hasValidPath = function(grid) {
    let r = grid.length; c = grid[0].length;
    let d = [[0, 1], [1, 0], [0, -1], [-1, 0]];
    let p = [[2, -1, 0, -1], 
            [-1, 3, -1, 1], 
            [-1, 2, 1, -1],
            [1, 0, -1, -1],
            [-1, -1, 3, 2],
            [3, -1, -1, 0]];
    
    let q = [[0, 0, 0], [0, 0, 1], [0, 0, 2], [0, 0, 3]];
    while (q.length) {
        let pre = q.shift();
        let x = pre[0], y = pre[1], di = pre[2];
        if (p[grid[x][y] - 1][di] == -1) continue;
        if (x == r - 1 && y == c - 1) return true;
        
        let dx = d[p[grid[x][y] - 1][di]][0], dy = d[p[grid[x][y] - 1][di]][1];
        let nx = x + dx, ny = y + dy;
        if (0 <= nx && nx < r && 0 <= ny && ny < c) {
            q.push([nx, ny, (p[grid[x][y] - 1][di] + 2) % 4]);
        }
    }
    return false
};