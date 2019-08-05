/**
 * @param {number} length
 */
var SnapshotArray = function(length) {
    this.dif = new Map();
    this.snaps = [];
};

/** 
 * @param {number} index 
 * @param {number} val
 * @return {void}
 */
SnapshotArray.prototype.set = function(index, val) {
    this.dif.set(index, val);
};

/**
 * @return {number}
 */
SnapshotArray.prototype.snap = function() {
    this.snaps.push(new Map(this.dif));
    return this.snaps.length - 1;
};

/** 
 * @param {number} index 
 * @param {number} snap_id
 * @return {number}
 */
SnapshotArray.prototype.get = function(index, snap_id) {
    if (this.snaps[snap_id].has(index)) {
        return this.snaps[snap_id].get(index);
    }
    return 0;
};