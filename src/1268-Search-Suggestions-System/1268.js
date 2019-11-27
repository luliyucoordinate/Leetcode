var suggestedProducts = function(products, searchWord) {
    products.sort();
    let l = 0, r = products.length - 1, res = [];

    for (let i = 0; i < searchWord.length; i++) {
        while (l <= r && (products[l].length <= i || products[l].charAt(i) != searchWord.charAt(i))) l++;
        while (l <= r && (products[r].length <= i || products[r].charAt(i) != searchWord.charAt(i))) r--;
        let tmp = [];
        for (let j = l; j < Math.min(l+3, r+1); j++)
            tmp.push(products[j]);
        res.push(tmp);
    } 
    return res;
};