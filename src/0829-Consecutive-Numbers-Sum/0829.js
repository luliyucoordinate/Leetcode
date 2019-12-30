var consecutiveNumbersSum = function(N) {
    let res = 1, i = 3;
    while (N % 2 == 0) N >>= 1;

    while (i * i <= N) {
        let cnt = 0;
        while (N % i == 0) {
            N = Math.floor(N / i);
            cnt++;
        }
        res *= cnt + 1;
        i += 2;
    }
    return N == 1 ? res : res * 2;
};