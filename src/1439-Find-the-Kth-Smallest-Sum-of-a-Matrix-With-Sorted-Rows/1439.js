var kthSmallest = function(mat, k) {
    let m = mat.length, n = mat[0].length;
    let l = m, r = m * 5000, res = -1;
    
    let dfs = function(cur, target, i, t) {
        if (cur > target) return 0;
        if (i == m) return 1;
        
        let ret = 0;
        for (let j = 0; j < n; j++) {
            let cnt = dfs(cur + mat[i][j], target, i + 1, t - ret);
            if (cnt == 0) break;
            ret += cnt;
            if (ret > k) break;
        }
        return ret;
    }

    while (l < r) {
        let mid = (l + r + 1) >> 1;
        let cnt = dfs(0, mid, 0, k);
        if (cnt >= k) {
            res = mid;
            r = mid - 1;
        } else {
            l = mid;
        }
    }
    return res;
};