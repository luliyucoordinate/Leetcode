var minStartValue = function(nums) {
    let pref = 0, min_pref = 0;
    for (let i of nums) {
        pref += i;
        min_pref = Math.min(min_pref, pref);
    }
    return 1 - min_pref;
};