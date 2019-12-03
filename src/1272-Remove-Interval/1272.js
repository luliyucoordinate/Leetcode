var removeInterval = function(intervals, toBeRemoved) {
    let res = [];
    for (let inter of intervals) {
        if (inter[0] >= toBeRemoved[1] || inter[1] <= toBeRemoved[0]) res.push(inter);
        else {
            if (inter[0] < toBeRemoved[0]) res.push([inter[0], toBeRemoved[0]]);
            if (inter[1] > toBeRemoved[1]) res.push([toBeRemoved[1], inter[1]]);
        }
    }
    return res;
};