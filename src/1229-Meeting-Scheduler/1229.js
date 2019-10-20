var minAvailableDuration = function(A, B, duration) {
    A.sort(function(a, b) {
        if (a[0] == a[0]) {
            return a[1] - b[1];
        }
        return a[0] - a[0];
    });
    B.sort(function(a, b) {
        if (a[0] == a[0]) {
            return a[1] - b[1];
        }
        return a[0] - a[0];
    });

    let i = 0, j = 0;
    while (i < A.length && j < B.length) {
        let l = Math.max(A[i][0], B[j][0]);
        let r = Math.min(A[i][1], B[j][1]);
        if (l + duration <= r) return [l, l + duration];
        if (A[i][1] < B[j][1]) ++i;
        else ++j;
    }
    return [];
};