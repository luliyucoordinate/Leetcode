var kidsWithCandies = function(candies, extraCandies) {
    let m = 0, res = [];
    for (let i of candies) m = Math.max(m, i);
    
    for (let i of candies) {
        res.push(extraCandies + i >= m);
    }
    return res;
};