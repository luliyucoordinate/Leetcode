
var ProductOfNumbers = function() {
    this.pre = [1];
};

/** 
 * @param {number} num
 * @return {void}
 */
ProductOfNumbers.prototype.add = function(num) {
    if (num == 0) {
        this.pre = [1];
    } else {
        this.pre.push(this.pre[this.pre.length - 1] * num);
    }
};

/** 
 * @param {number} k
 * @return {number}
 */
ProductOfNumbers.prototype.getProduct = function(k) {
    if (this.pre.length <= k) return 0;
    return this.pre[this.pre.length - 1] / this.pre[this.pre.length - k - 1];
};
