var minKnightMoves = function(x, y) {
    x = Math.abs(x), y = Math.abs(y);
    if (x + y == 1) return 3;
    var res = Math.max(Math.max(Math.ceil(x/2), Math.ceil(y/2)), Math.ceil((x + y)/3));
    res += (res ^ x ^ y) & 1;
    return res;
};