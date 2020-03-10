var generateTheString = function(n) {
    return 'a'.repeat(n - 1) + (n % 2 ? 'a' : 'b');
};