
var FileSystem = function() {
    this.paths = {};
    this.paths[""] = -1;
};

/** 
 * @param {string} path 
 * @param {number} value
 * @return {boolean}
 */
FileSystem.prototype.create = function(path, value) {
    var parent = path.substr(0, path.lastIndexOf("/"));
    if (!this.paths[parent]) return false;
    this.paths[path] = value;
    return true;
};

/** 
 * @param {string} path
 * @return {number}
 */
FileSystem.prototype.get = function(path) {
    if (!this.paths[path]) return -1;
    return this.paths[path];
};