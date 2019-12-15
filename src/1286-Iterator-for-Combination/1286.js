/**
 * @param {string} characters
 * @param {number} combinationLength
 */
var CombinationIterator = function(ch, l) {
    this.res = [];
    var combine = (s, cur) => {
        if (cur.length == l) {
            this.res.push(cur);
            return;
        }
        for (let i = s; i <= ch.length - (l - cur.length); i++) {
            combine(i + 1, cur + ch[i]);
        }
    }
    combine(0, "");
};

/**
 * @return {string}
 */
CombinationIterator.prototype.next = function() {
    return this.res.shift();
};

/**
 * @return {boolean}
 */
CombinationIterator.prototype.hasNext = function() {
    return this.res.length != 0;
};