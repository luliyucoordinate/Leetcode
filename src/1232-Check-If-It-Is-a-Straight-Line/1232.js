var checkStraightLine = function(c) {
    for (let i = 2; i < c.length; i++) {
        if ((c[i][0] - c[0][0]) * (c[i][1] - c[1][1]) != 
            (c[i][0] - c[1][0]) * (c[i][1] - c[0][1])) 
            return false;
    }
    return true;
};