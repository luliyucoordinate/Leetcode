var numTeams = function(rating) {
    if (rating.length < 3) return 0;
    
    let update = function(tr, x, v) {
        for (let i = x; i <= N; i += i & -i) tr[i] += v;
    }

    let getPrefixSum = function(tr, x) {
        let res = 0;
        for (let i = x; i > 0; i -= i & -i) res += tr[i];
        return res;
    }

    let getSuffixSum = function(tr, i) {
        return getPrefixSum(tr, N) - getPrefixSum(tr, i - 1);
    }

    let N = 100000;
    let leftTree = new Array(N + 1).fill(0), rightTree = new Array(N + 1).fill(0);

    for (let r of rating) update(rightTree, r, 1);

    let res = 0;
    for (let r of rating) {
        update(rightTree, r, -1);
        res += getPrefixSum(leftTree, r - 1) * getSuffixSum(rightTree, r + 1) +
                getSuffixSum(leftTree, r + 1) * getPrefixSum(rightTree, r - 1);  
        update(leftTree, r, 1);
    }

    return res;
};