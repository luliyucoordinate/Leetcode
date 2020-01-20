var videoStitching = function(clips, T) {
    clips.sort((a, b) => a[0] - b[0]);
    let pre = -1, cur = 0, step = 0;
    for (let it of clips) {
        if (cur >= T || it[0] > cur) break;
        if (pre < it[0] && it[0] <= cur) {
            step++;
            pre = cur;
        }
        cur = Math.max(cur, it[1]);
    }
    return cur >= T ? step : -1;
};