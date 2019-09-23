var smallestCommonElement = function(mat) {
    var r = mat.length, c = mat[0].length;
b:  for (var i = 0; i < c; ++i) {
        for (var j = 1; j < r; ++j) {
            var l = 0, p = c - 1;
            while (l < p) {
                var mid = (l + p) >> 1;
                if (mat[j][mid] < mat[0][i]) l = mid + 1;
                else p = mid;
            }
            if (mat[j][l] == mat[0][i]) continue;
            else continue b; 
        }
        return mat[0][i];
    }
    return -1;
};