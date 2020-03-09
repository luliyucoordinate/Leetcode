var findTheLongestSubstring = function(s) {
    let vowels = new Array(26).fill(0);
    vowels[0] = 1;
    vowels[4] = 2;
    vowels[8] = 4;
    vowels[14] = 8;
    vowels[20] = 16;

    let vis = new Array(32).fill(0);
    vis[0] = 1;
    let res = 0, cur = 0;
    for (let i = 0; i < s.length; i++) {
        cur ^= vowels[s[i].charCodeAt() - 97];
        if (vis[cur] == 0) vis[cur] = i + 2;
        res = Math.max(res, i - vis[cur] + 2);
    }
    return res;
};