var buildArray = function(target, n) {
    let res = [], k = 1;

    for (let i = 0; i < target.length; i++, k++) {
        if (target[i] == k) { 
            res.push("Push");
        } else { 
            i--;
            res.push("Push");
            res.push("Pop");
        }
    }
    return res;
};