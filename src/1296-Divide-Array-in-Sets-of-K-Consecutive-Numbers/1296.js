var isPossibleDivide = function(nums, k) {
    if (nums.length % k != 0) return false;
    let cnt = new Map();
    for (let i of nums) {
        cnt.set(i, (cnt.get(i) || 0) + 1);
    }
    
    for (let i of nums) {
        let l = i;
        while (cnt.get(--l));
        while (l <= i) {
            let t = cnt.get(l);
            if (t) {
                for (let j = l; j < l + k; j++) {
                    let pre = cnt.get(j) || 0;
                    if (pre < t) return false;
                    cnt.set(j, pre - t);
                }
            } else l++;
        }
    }
    return true;
};