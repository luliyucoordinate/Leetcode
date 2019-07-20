var earliestAcq = function(logs, N) {
    logs.sort(function(a, b){
        return a[0] < b[0];
    });

    var s = [];
    for (var i = 0; i <= N; ++i) s[i] = i;
    function find(x) {
        if (s[x] != x) s[x] = find(s[x]);
        return s[x];
    };

    var cnt = 0;
    for (var i = 0; i < logs.length; ++i) {
        var rx = find(logs[i][1]), ry = find(logs[i][2]);
        if (rx != ry) {
            s[rx] = ry;
            cnt++;
        }
        if (cnt == N - 1) return logs[i][0];
    }
    return -1;
};