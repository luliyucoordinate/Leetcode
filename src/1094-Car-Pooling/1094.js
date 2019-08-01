var carPooling = function(trips, capacity) {
    var tmp = [];
    for (let v of trips) {
        tmp.push([v[1], v[0]]);
        tmp.push([v[2], -v[0]]);
    }
    tmp.sort(function(a, b){
        if (a[0] == b[0]) return a[1] - b[1];
        else return a[0] - b[0];
    });
    
    var res = 0;
    for (let v of tmp) {
        res += v[1];
        if (res > capacity) return false;
    }
    return true;
};