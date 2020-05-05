var destCity = function(paths) {
    let s = {};
    for (let path of paths) s[path[0]] = 1;
    for (let path of paths) {
        if (!(path[1] in s)) return path[1]
    }
    return "";
};