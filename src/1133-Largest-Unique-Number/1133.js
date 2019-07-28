var largestUniqueNumber = function(A) {
    A.sort(function(a, b) {
        return a - b;
    });
    while (A.length > 1 && A.slice(-1) == A[A.length - 2]) {
        bk = A[A.length - 1];
        while (A.length && A.slice(-1) == bk) {
            A.pop();
        }
    }
    if (A.length) return A.slice(-1);
    return -1;
};