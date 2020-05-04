var findDiagonalOrder = function(nums) {
    let mat = [];
    for (let i = 0; i < nums.length; i++) {
        for (let j = 0; j < nums[i].length; j++) {
            if (i + j >= mat.length) mat.push([]);
            mat[i + j].unshift(nums[i][j]);
        }
    }
    
    let res = [];
    for (let diag of mat) {
        for (let num of diag) {
            res.push(num);
        }
    }
    return res;
};