var xorQueries = function(arr, queries) {
    let A = new Array(arr.length + 1);
    A.fill(0);
    for (let i = 1; i <= arr.length; i++) {
        A[i] = A[i - 1] ^ arr[i - 1];
    } 

    let res = new Array(queries.length);
    for (let i = 0; i < queries.length; i++) {
        res[i] = A[queries[i][0]] ^ A[queries[i][1] + 1];
    }
    return res;
};