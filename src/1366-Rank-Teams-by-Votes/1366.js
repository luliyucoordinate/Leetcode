var rankTeams = function(votes) {
    let n = votes[0].length, cnt = [];
    for (let i = 0; i < 26; i++) {
        cnt[i] = new Array(n + 1).fill(0);
        cnt[i][n] = i;
    }
    
    for (let vote of votes) {
        for (let i = 0; i < n; i++) {
            cnt[vote.charCodeAt(i) - 65][i]--;
        }
    }
    return votes[0].split('').sort((a, b) => {
        for (let i = 0; i <= n; i++) {
            if (cnt[a.charCodeAt() - 65][i] == cnt[b.charCodeAt() - 65][i]) continue;
            return cnt[a.charCodeAt() - 65][i] - cnt[b.charCodeAt() - 65][i];
        }
        return 0;
    }).join('');
};