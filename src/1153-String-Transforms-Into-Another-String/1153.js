var canConvert = function(str1, str2) {
    var s2 = new Set(str2);
    if (s2.size == 26) return str1 == str2;
    var d = {};
    for (var i = 0; i < str1.length; ++i) {
        if (d[str1[i]]) {
            if (d[str1[i]] != str2[i]) return false;
        } else d[str1[i]] = str2[i];
    }
    return true;
};