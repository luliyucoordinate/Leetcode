var sumFourDivisors = function(nums) {
    let get_divisors = function(x) {
        let res = 0, cnt = 0;
        for (let i = 1; i * i <= x; i ++ ) {
            if (x % i == 0) {
                res += i; cnt++;
                if (i * i != x) {
                    res += x / i;
                    cnt++;
                }
                if (cnt > 4) return 0;
            }
        }
        return cnt < 4 ? 0 : res;
    }
    
    let res = 0;
    for (let num of nums) res += get_divisors(num);
    return res;
};