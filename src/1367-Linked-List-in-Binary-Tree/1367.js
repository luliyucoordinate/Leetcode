var isSubPath = function(head, root) {
    let arr = [], f = [-1];
    let node = head, i = -1;
    
    while (node != null) {
        while (i != -1 && node != null && node.val != arr[i]) i = f[i];
        i++;
        
        arr.push(node.val);
        f.push(i);
        node = node.next;
    }
    
    let dfs = function(cur, u) {
        if (cur == null) return false;
        
        while (u != -1 && cur.val != arr[u]) u = f[u];
        u++;
        
        if (u == arr.length) return true;
        return dfs(cur.left, u) || dfs(cur.right, u);
    }
    
    return dfs(root, 0);
};