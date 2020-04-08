var numSteps = function(s) {
    let res = 0, add = 0, n = s.length;
        
    for (let i = n - 1; i > 0; i--) {
        res++;
        if (s.charCodeAt(i) - 48 + add == 1) {
            add = 1;
            res++;
        }
    }
    return res + add;
};