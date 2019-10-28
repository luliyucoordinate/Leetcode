var maxLength = function(arr) {
    let arr_len = arr.length, res = 0;
    let isUnique = function(s) {
        let tmp = new Array(26); tmp.fill(0);
        for (let a of s) tmp[a.charCodeAt() - 97]++;
        for (let i = 0; i < 26; i++) if (tmp[i] > 1) return false;
        return true;
    }
    
    let dfs = function(index, path) {
        let uq = isUnique(path);
        if (uq) res = Math.max(res, path.length);
        if (index == arr_len || !uq) return;
        for (let i = index; i < arr_len; i++)
            dfs(i + 1, path + arr[i])
    }
    dfs(0, "");
    return res;
};