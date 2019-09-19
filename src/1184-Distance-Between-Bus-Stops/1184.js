var distanceBetweenBusStops = function(d, l, r) {
    if (l > r) {
        var t = l;
        l = r, r = t;
    }
    var k = 0, v = 0;
    for (var i = 0; i < d.length; ++i)  {
        if (i < l || i >= r) k += d[i]; 
        else v += d[i];
    } 
    return Math.min(k, v);
};