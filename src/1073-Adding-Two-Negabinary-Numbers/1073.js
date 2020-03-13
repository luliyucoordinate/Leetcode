var addNegabinary = function(arr1, arr2) {
    let res = [];
    let carry = 0, l1 = arr1.length, l2 = arr2.length;
    
    while (carry || l1 || l2) {
        if (l1) carry += arr1[--l1];
        if (l2) carry += arr2[--l2];
        res.push(carry & 1);
        carry = -(carry >> 1);
    }
    
    while (res.length > 1 && res[res.length - 1] == 0) res.pop();
    res.reverse();
    return res;
};