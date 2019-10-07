var isValidPalindrome = function(s, k) {
    var lcs = function(text1, text2) {
        var m = text1.length, n = text2.length;
        var l = new Array(m+1);
        for (var i = 0; i <= m; i++) {
            l[i] = new Array(n+1);
            l[i].fill(0);
        }
        for (var i = 1; i <= m; i++) {
            for (var j = 1; j <= n; j++) {
                if (text1[i-1] == text2[j-1])
                    l[i][j] = l[i-1][j-1] + 1;
                else l[i][j] = Math.max(l[i-1][j], l[i][j-1]);
            }
        }
        return l[m][n];
    };
    return s.length - lcs(s, s.split("").reverse().join("")) <= k;
};