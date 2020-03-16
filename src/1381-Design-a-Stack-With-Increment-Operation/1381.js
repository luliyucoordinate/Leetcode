/**
 * @param {number} maxSize
 */
var CustomStack = function(maxSize) {
    this.c = maxSize;
    this.s = [];
    this.inc = [];
};

/** 
 * @param {number} x
 * @return {void}
 */
CustomStack.prototype.push = function(x) {
    if (this.s.length < this.c) {
        this.s.push(x);
        this.inc.push(0);
    }
};

/**
 * @return {number}
 */
CustomStack.prototype.pop = function() {
    if (this.s.length == 0) return -1;
    let i = this.inc.length - 1;
    if (i > 0) {
        this.inc[i - 1] += this.inc[i];
    }
    return this.s.pop() + this.inc.pop();
};

/** 
 * @param {number} k 
 * @param {number} val
 * @return {void}
 */
CustomStack.prototype.increment = function(k, val) {
    if (this.inc.length) {
        this.inc[Math.min(k, this.inc.length) - 1] += val;
    }
};