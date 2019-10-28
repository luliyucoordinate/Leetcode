var findSolution = function(customfunction, z) {
    let res = [], y = 1000;
    for (let x = 1; x <= 1000; x++) {
        while (y > 1 && customfunction.f(x, y) > z) {
            y--;
        }
        if (customfunction.f(x, y) == z) res.push([x, y]);
    }
    return res;
};