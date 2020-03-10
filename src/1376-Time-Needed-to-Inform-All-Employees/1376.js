var numOfMinutes = function(n, headID, manager, informTime) {
    let son = [];
    for (let i = 0; i < n; i++) son[i] = [];
    for (let i = 0; i < manager.length; i++) {
        if (manager[i] != -1) son[manager[i]].push(i);  
    }
    
    let dfs = function(x) {
        let res = 0;
        for (let n of son[x]) {
            res = Math.max(res, dfs(n));
        }
        return res + informTime[x];
    }
    return dfs(headID);
};