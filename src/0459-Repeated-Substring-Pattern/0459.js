var repeatedSubstringPattern = function(s) {
    return (s + s).slice(1, -1).indexOf(s) != -1;
};