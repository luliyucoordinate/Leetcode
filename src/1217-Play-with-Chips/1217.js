var minCostToMoveChips = function(chips) {
    let res = [0, 0];
    for (let c of chips) res[c%2]++;
    return Math.min(res[0], res[1]);
};