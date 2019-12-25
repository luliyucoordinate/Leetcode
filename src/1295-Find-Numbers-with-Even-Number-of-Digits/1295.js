var findNumbers = function(nums) {
    let res = 0;
    for (let n of nums) {
        let x = 0;
        while (n) {
            n = Math.floor(n / 10);
            x++;
        }
        if (x % 2 == 0) res++;
    }
    return res;
};