var maxDiff = function(num) {
    String.prototype.replaceAll = function(s1, s2) {     
        return this.replace(new RegExp(s1,"gm"), s2);     
    } 

    let a = num + "", b = num + "";
    for (let c of a) {
        if (c != '9') {
            a = a.replaceAll(c, '9');
            break;
        }
    }
    
    if (b.charAt(0) != '1') {
        b = b.replaceAll(b.charAt(0), '1');
    } else {
        for (let i = 1; i < b.length; i++) {
            let bi = b.charAt(i);
            if (bi != '0' && bi != '1') {
                b = b.replaceAll(bi, '0');
                break;
            }
        }
    }
    return Number(a) - Number(b);
};