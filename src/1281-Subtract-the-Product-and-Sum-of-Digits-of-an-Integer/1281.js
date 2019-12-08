/**
 * @param {number} n
 * @return {number}
 */
var subtractProductAndSum = function(n) {
    let sum = 0, product = 1;
    while (n > 0) {
        sum += n % 10;
        product *= n % 10;
        n = Math.floor(n / 10);
    }
    return product - sum;
};