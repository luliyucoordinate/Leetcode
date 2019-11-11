var maxScoreWords = function(words, letters, score) {
    let cnt = Array(score.length), n = words.length;
    cnt.fill(0);
    for (let c of letters) {
        cnt[c.charCodeAt() - 97]++;
    }
    let dfs = function(i) {
        if (i == n) return 0;
        let res = Math.max(0, dfs(i + 1)), tmp = 0, val = 1;
        for (let c of words[i]) {
            let t = c.charCodeAt() - 97;
            cnt[t]--;
            tmp += score[t];
            if (cnt[t] < 0) val = 0;
        }
        if (val == 1) res = Math.max(res, dfs(i + 1) + tmp);
        for (let c of words[i]) cnt[c.charCodeAt() - 97]++;
        return res
    }
    return dfs(0);
};