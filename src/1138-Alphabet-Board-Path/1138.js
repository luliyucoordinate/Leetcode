var alphabetBoardPath = function(target) {
    var res = "";
    var x = 0, y = 0;
    for (let ch of target) {
        var x1 = Math.floor((ch.charCodeAt(0) - 97)/5), y1 = (ch.charCodeAt(0) - 97)%5;
        var l = x1 - x, c = y1 - y;
        if (l < 0) {
            for (var i = 0; i < -l; ++i) {
                res += "U";
            }
        }
        if (c < 0) {
            for (var i = 0; i < -c; ++i) {
                res += "L";
            }
        }
        if (l > 0) {
            for (var i = 0; i < l; ++i) {
                res += "D";
            }
        }
        if (c > 0) {
            for (var i = 0; i < c; ++i) {
                res += "R";
            }
        }
        res += "!";
        x = x1, y = y1;
    }
    return res;
};