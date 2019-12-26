var maxCandies = function(status, candies, keys, containedBoxes, initialBoxes) {
    let q = initialBoxes, res = 0;
    while (q.length > 0) {
        let changed = false;
        for (let q_len = q.length; q_len > 0; q_len--) {
            let b = q.shift();
            if (status[b] == 1) {
                changed = true;
                res += candies[b];
                q.push(...containedBoxes[b]);
                for (let i of keys[b]) status[i] = 1;
            } else q.push(b);
        }
        if (!changed) return res;
    }
    return res;
};