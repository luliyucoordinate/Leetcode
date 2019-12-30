var deepestLeavesSum = function(root) {
    let q = [root], res = 0;
    
    while (q.length > 0) {
        let n = q.length;
        res = 0;
        
        while (n--) {
            let cur = q.shift();
            res += cur.val;
            if (cur.left) q.push(cur.left);
            if (cur.right) q.push(cur.right);
        }
    }
    return res;
};