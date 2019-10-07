var countSteppingNumbers = function(l, r) {
    var res = [];
    var bfs = function(s) {
        var q = [s];
        while (q.length > 0) {
            var pre = q.shift();
            if (pre >= l && pre <= r) res.push(pre);
            if (pre == 0 || pre > r) continue;
            
            var lt = pre % 10;
            var s1 = pre * 10 + lt + 1, s2 = pre * 10 + lt - 1;
            if (lt == 0) q.push(s1);
            else if (lt == 9) q.push(s2);
            else 
            {
                q.push(s1); 
                q.push(s2);
            }
        }
    }
    for (var i = 0; i <= 9; i++) bfs(i);
    res.sort((a, b) => a - b);
    return res;
};