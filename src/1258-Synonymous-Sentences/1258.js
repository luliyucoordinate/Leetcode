/**
 * @param {string[][]} synonyms
 * @param {string} text
 * @return {string[]}
 */
var generateSentences = function(synonyms, text) {
    let parent = new Map(), data = new Map();
    let find = function(x) {
        if (!parent.has(x)) parent.set(x, x);
        if (x != parent.get(x)) {
            parent.set(x, find(parent.get(x)));
        }
        return parent.get(x);
    }
    
    for (let it of synonyms) {
        let x = find(it[0]), y = find(it[1]);
        if (x != y) parent.set(x, y);
    }
    
    for (let k of parent.keys()) {
        let fk = find(k);
        if (!data.has(fk)) {
            data.set(find(k), []);
        }
        data.get(fk).push(k);
    }
    
    let txt = text.split(" "), res = [""];
    for (let w of txt) {
        let fw = find(w);
        if (data.has(fw)) {
            let tmp = [];
            for (let s of res) {
                for (let v of data.get(fw)) {
                    tmp.push(s + " " + v);
                }
            }
            res = tmp;
        } else {
            for (let i = 0; i < res.length; i++) {
                res[i] += " " + w;
            }
        }
    }
    for (let i = 0; i < res.length; i++) {
        res[i] = res[i].substring(1);
    }
    res.sort();
    return res;
};