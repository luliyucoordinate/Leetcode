var oddEvenJumps = function(A) {
    let n = A.length, d = new Array(n);
    for (let i = 0; i < n; i++) d[i] = i;
    
    let st = function(data) {
        let s = [], res = new Array(n);
        res.fill(0);
        for (let i of data) {
            while (s.length && s[s.length - 1] < i) {
                res[s.pop()] = i;
            }
            s.push(i);
        }
        return res;
    }
    d.sort(function(i, j) {
        if(A[i] == A[j]) return i - j;
        else return A[i] - A[j];
    });
    let n1 = st(d);
    d.sort(function(i, j) {
        if(A[i] == A[j]) return i - j;
        else return A[j] - A[i];
    });
    let n2 = st(d);
    
    let h = new Array(n), l = new Array(n);
    h.fill(0); l.fill(0);
    h[n - 1] = l[n - 1] = 1;
    for (let i = n - 2; i >= 0; i--) {
        h[i] = l[n1[i]]
        l[i] = h[n2[i]]
    }
    let res = 0;
    for (let i of h) {
        if (i) res++;
    }
    return res;
};