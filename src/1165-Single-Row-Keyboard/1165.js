var calculateTime = function(keyboard, word) {
    var d = {};
    for (var i = 0; i < keyboard.length; ++i) {
        d[keyboard[i]] = i;
    }
    
    var res = 0, pre = 0;
    for (let c of word) {
        res += Math.abs(d[c] - pre);
        pre = d[c];
    }
    return res;
};