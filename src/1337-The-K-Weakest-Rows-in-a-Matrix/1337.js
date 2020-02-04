var kWeakestRows = function(mat, k) {
    let numOnes = function(row) {
        let l = 0, r= row.length;
        while (l < r) {
            let mid = (l + r) >> 1;
            if (row[mid] == 1) l = mid + 1;
            else r = mid;
        }
        return l;
    }
    
    let data = [], res = [];
    for (let i = 0; i < mat.length; i++) {
        data.push([numOnes(mat[i]), i]);
    }
    
    data.sort((a, b) => a[0] - b[0] || a[1] - b[1]);
    for (let i = 0; i < k; i++) {
        res.push(data[i][1]);
    }
    return res;
};