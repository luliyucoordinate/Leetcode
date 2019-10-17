/**
 * @param {number[]} nums
 */
var NumArray = function(data) {
    this.nums = data;
    this.tree = new Array(data.length + 1);
    this.tree.fill(0);
    for (let i = 0; i < data.length; i++) {
        this._update(i+1, data[i]);
    }
};

NumArray.prototype._update = function(i, val) {
    while (i < this.tree.length) {
        this.tree[i] += val;
        i += this.lowbit(i);
    }
};

NumArray.prototype.query = function(i) {
    let res = 0;
    while (i) {
        res += this.tree[i];
        i -= this.lowbit(i);
    }
    return res;
};

NumArray.prototype.lowbit = function(x) {
    return x & (-x);
};
/** 
 * @param {number} i 
 * @param {number} val
 * @return {void}
 */
NumArray.prototype.update = function(i, val) {
    this._update(i+1, val - this.nums[i]);
    this.nums[i] = val;
};

/** 
 * @param {number} i 
 * @param {number} j
 * @return {number}
 */
NumArray.prototype.sumRange = function(i, j) {
    return this.query(j+1) - this.query(i);
};