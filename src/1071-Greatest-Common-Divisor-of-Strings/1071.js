var gcdOfStrings = function(s1, s2) {
    let gcd = function(a, b) {
        return b ? gcd(b, a % b) : a;
    }
    return s1 + s2 == s2 + s1 ? s1.substring(0, gcd(s1.length, s2.length)) : "";
};