var lastStoneWeightII = function(stones) {
    let sum = 0;
    for (let s of stones) sum += s;
    let mem = new Array((sum>>1) + 1);
    mem[0] = 1;
    
    for (let i of stones) {
        for (let j = sum>>1; j >= i; --j) {
            mem[j] |= mem[j - i];
        }
    }
    for (let i = sum>>1; i > 0; --i) {
        if (mem[i]) return sum - 2*i;
    }
    return 0;
};