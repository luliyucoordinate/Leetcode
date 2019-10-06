var arraysIntersection = function(arr1, arr2, arr3) {
    let d = new Array(2001);
    d.fill(0);
    for (let x of arr1) d[x]++;
    for (let x of arr2) d[x]++;
    
    let res = [];
    for (let x of arr3) {
        if (d[x] == 2) res.push(x);
    }
    return res;
};