var deleteTreeNodes = function(n, parent, value) {
    for (let i = n - 1; i > 0; i--) {
        value[parent[i]] += value[i];
    }
    
    let zeros = 0, isZero = new Array(n);
    isZero.fill(0);
    for (let i = 0; i < n; i++) {
        if (parent[i] > 0 && isZero[parent[i]] || value[i] == 0) {
            isZero[i] = 1;
            zeros++;
        }
    }
    return n - zeros;
};