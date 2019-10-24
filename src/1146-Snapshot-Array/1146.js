/**
 * @param {number} length
 */
var SnapshotArray = function(length) {
    this.dif = {};
    this.snaps = [];
};

/** 
 * @param {number} index 
 * @param {number} val
 * @return {void}
 */
SnapshotArray.prototype.set = function(index, val) {
    this.dif[index] = val;
};

/**
 * @return {number}
 */
SnapshotArray.prototype.snap = function() {
    let {...newDif} = this.dif;
    this.snaps.push(newDif);
    return this.snaps.length - 1;
};

/** 
 * @param {number} index 
 * @param {number} snap_id
 * @return {number}
 */
SnapshotArray.prototype.get = function(index, snap_id) {
    if (this.snaps[snap_id][index]) {
        return this.snaps[snap_id][index];
    }
    return 0;
};