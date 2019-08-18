var maxLevelSum = function(root) {
    if (!root) return 0;
    
    var q = [root];
    var res = 0, level = 0, maxSum = 0;
    
    while (q.length) {
        var curSum = 0, qLen = q.length;
        for (var i = 0; i < qLen; i++) {
            var node = q.shift();
            curSum += node.val;
            if (node.left) q.push(node.left);
            if (node.right) q.push(node.right);
        }
        level++;
        if (curSum > maxSum) {
            maxSum = curSum; res = level;
        }
    }
    return res;
};