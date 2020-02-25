var closestDivisors = function(num) {
    for (let a = Math.floor(Math.sqrt(num + 2)); a > 0; a--) {
        if ((num + 1) % a == 0) return [a, Math.floor((num + 1) / a)];
        if ((num + 2) % a == 0) return [a, Math.floor((num + 2) / a)];
    }
    return [];
};