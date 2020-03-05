var distributeCandies = function(candies, num_people) {
    let p = Math.floor((Math.sqrt(8 * candies + 1) - 1) / 2);
    let R = candies - Math.floor((p + 1) * p / 2);
    let r = Math.floor(p / num_people), c = p % num_people;
    
    let res = new Array(num_people).fill(0);
    for (let i = 0; i < num_people; i++) {
        res[i] = (2 * (i + 1) + (r - 1) * num_people) * r >> 1;
        if (i < c) res[i] += i + 1 + r * num_people;
    }       
    res[c] += R;
    return res;
};