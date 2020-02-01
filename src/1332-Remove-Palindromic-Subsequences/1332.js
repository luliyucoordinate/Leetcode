var removePalindromeSub = function(s) {
    return s.length == 0 ? 0 : s == s.split("").reverse().join("") ? 1 : 2;
};