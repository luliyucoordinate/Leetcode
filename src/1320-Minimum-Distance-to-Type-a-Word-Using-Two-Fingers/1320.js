var minimumDistance = function(word) {
    let dp = new Array(26),sum_dis = 0, max_a = 0;
    dp.fill(0);
    
    let dis = function(a, b) {
        return Math.abs(Math.floor(a/6) - Math.floor(b/6)) + Math.abs(a%6 - b%6);
    }
    
    for (let i = 0; i < word.length - 1; i++) {
        let a = word.charCodeAt(i) - 65, c = word.charCodeAt(i + 1) - 65;
        for (let b = 0; b < 26; b++) {
            dp[a] = Math.max(dp[a], dp[b] + dis(a, c) - dis(b, c));
        }
        max_a = Math.max(max_a, dp[a]);
        sum_dis += dis(a, c);
    }
    return sum_dis - max_a;
};