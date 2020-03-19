var longestPalindrome = function(s) {
    let cnt = new Array(128).fill(0);
    for (let c of s) cnt[c.charCodeAt()]++;
    
    let res = 0;
    for (let i of cnt) res += Math.floor(i / 2) * 2;
    return res == s.length ? res : res + 1;
};