var arrayRankTransform = function(arr) {
    let arrs = arr.slice();
    arrs.sort((a, b) => a - b);
    let st = new Map(), rank = 1;
    
    for (let i = 0; i < arrs.length; i++) {
        if (!st.has(arrs[i])) {
            st.set(arrs[i], rank++);
        }
    }
    
    for (let i = 0; i < arr.length; i++) {
        arr[i] = st.get(arr[i]);
    }
    return arr;
};