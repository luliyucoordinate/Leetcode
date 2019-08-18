var countCharacters = function(words, chars) {
    var cnt = Array(26);
    cnt.fill(0);
    for (let c of chars) cnt[c.charCodeAt() - 97]++;
    
    var res = 0;
    for (let word of words) {
        var tmp = cnt.slice();
        var match = true;
        for (let c of word) {
            if (--tmp[c.charCodeAt() - 97] < 0) {
                match = false;
                break;
            }
        }
        if (match) res += word.length;
    }
    return res;
};