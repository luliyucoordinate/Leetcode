var removeSubfolders = function(folder) {
    folder.sort();
    let res = [], l = 2, parent = '';
    for (let f of folder) {
        if (f.substr(0, l) != parent) {
            l = f.length + 1;
            parent = f + '/';
            res.push(f);
        }
    }
    return res;
};