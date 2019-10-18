var preimageSizeFZF = function(K) {
    let x = 1;
    while (x < K) x = x * 5 + 1;
    while (x > 1) {
        K %= x;
        if (x - 1 == K) return 0;
        x = Math.floor((x - 1) / 5);
    }
    return 5;
};