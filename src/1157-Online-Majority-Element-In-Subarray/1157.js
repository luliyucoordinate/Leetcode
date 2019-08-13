/**
 * @param {number[]} arr
 */
var MajorityChecker = function(arr) {
    this.data = arr;
    this.indexs = new Map();
    for (var i = 0; i < arr.length; ++i) {
        if (!this.indexs.has(arr[i])) this.indexs.set(arr[i], Array());
        this.indexs.get(arr[i]).push(i);
    }
};

/** 
 * @param {number} left 
 * @param {number} right 
 * @param {number} threshold
 * @return {number}
 */
MajorityChecker.prototype.query = function(left, right, threshold) {
    for (var i = 0; i < 7; ++i) {
        var num = this.data[Math.round(Math.random()*(right - left) + left)];
        var l = 0, r = this.indexs.get(num).length - 1;
        while (l < r) {
            var mid = l + r >> 1;
            if (this.indexs.get(num)[mid] >= left) {
                r = mid;
            } else l = mid + 1;
        }
        var t1 = l, t2 = 0;
        
        l = 0, r = this.indexs.get(num).length - 1;
        while (l < r) {
            var mid = l + r + 1 >> 1;
            if (this.indexs.get(num)[mid] <= right) {
                l = mid;
            } else r = mid - 1;
        }
        t2 = l + 1;
        if (t2 - t1 >= threshold) return num;
    }
    return -1;
};