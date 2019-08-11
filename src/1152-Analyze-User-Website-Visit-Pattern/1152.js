var mostVisitedPattern = function(username, timestamp, website) {
    var data = new Map();
    var n = username.length;
    for (var i = 0; i < n; ++i) {
        for (var j = 0; j < n; ++j) {
            if (timestamp[i] < timestamp[j] 
               && username[i] == username[j])
            for (var k = 0; k < n; ++k) {
                if (timestamp[j] < timestamp[k]
                   && username[j] == username[k])
                {
                    var t = website[i] + "," + website[j] + "," + website[k];
                    if (!data.has(t)) data.set(t, new Set())
                    data.get(t).add(username[k]);
                }
            }
        }
    }
    var ta = Array.from(data);
    ta.sort(function(a, b) {
        if (a[1].size == b[1].size) return a[0].localeCompare(b[0]);
        return  b[1].size - a[1].size;
    });
    return ta[0][0].split(",");
};