var minJumps = function(arr) {
    let g = new Map(), values = new Map();
    let n = arr.length, step = 0;
    for (let i = 0; i < n; i++) {
        if (!g.has(arr[i])) g.set(arr[i], []);
        g.get(arr[i]).push(i); 
    }
    
    let vis = new Array(n); vis.fill(0);
    
    let q = [0];
    while (q.length) {
        let k = q.length;
        while (k--) {
            let pre = q.shift();
            if (pre == n - 1) return step;
            
            if (pre - 1 >= 0 && vis[pre - 1] == 0) {
                vis[pre - 1] = 1; 
                q.push(pre - 1);
            }

            if (pre + 1 < n && vis[pre + 1] == 0) {
                vis[pre + 1] = 1; 
                q.push(pre + 1);
            }

            if (values.has(arr[pre])) continue;
            values.set(arr[pre], 1);
            for (let i of g.get(arr[pre])) {
                if (vis[i] == 0) {
                    vis[i] = 1; 
                    q.push(i);
                }
            }
        }
        step++;
    }
    return step;
};