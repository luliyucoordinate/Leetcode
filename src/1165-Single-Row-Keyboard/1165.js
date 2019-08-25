var calculateTime = function(keyboard, word) {
    var d = new Map();
    for (var i = 0; i < keyboard.length; ++i) {
        d.set(keyboard[i], i);
    }
    
    var res = 0, pre = 0;
    for (let c of word) {
        res += Math.abs(d.get(c) - pre);
        pre = d.get(c);
    }
    return res;
};