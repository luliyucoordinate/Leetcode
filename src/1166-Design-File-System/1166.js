
var FileSystem = function() {
    this.paths = new Map();
    this.paths.set("", -1);
};

/** 
 * @param {string} path 
 * @param {number} value
 * @return {boolean}
 */
FileSystem.prototype.create = function(path, value) {
    var parent = path.substr(0, path.lastIndexOf("/"));
    if (!this.paths.get(parent)) return false;
    this.paths.set(path, value);
    return true;
};

/** 
 * @param {string} path
 * @return {number}
 */
FileSystem.prototype.get = function(path) {
    if (!this.paths.get(path)) return -1;
    return this.paths.get(path);
};