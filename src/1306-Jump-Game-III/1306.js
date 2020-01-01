var canReach = function(arr, start) {
    let q = [start], vis = new Array(arr.length);
    vis.fill(0);
    vis[start] = 1;
    
    while (q.length) {
        let cur = q.shift();
        if (arr[cur] == 0) return true;
        
        vis[cur] = 1;
        let a = cur + arr[cur], b = cur - arr[cur];
        if (a >= 0 && a < arr.length && !vis[a]) q.push(a);
        if (b >= 0 && b < arr.length && !vis[b]) q.push(b);
    }
    return false;
};