var numOfBurgers = function(t, c) {
    return t % 2 == 0 && c * 2 <= t && t <= c * 4 ? [t / 2 - c, c * 2 - t / 2] : [];
};