var watchedVideosByFriends = function(watchedVideos, friends, id, level) {
    let seen = new Array(friends.length);
    seen.fill(0);
    seen[id] = 1;
    let q = [id];

    while (level--) {
        for (let i = q.length; i > 0; i--) {
            let idx = q.shift();
            for (let p of friends[idx]) {
                if (seen[p] == 0) {
                    seen[p] = 1;
                    q.push(p);
                }
            }
        }
    }

    let cnt = new Map();
    for (let v of q) {
        for (let s of watchedVideos[v]) {
            cnt.set(s, (cnt.get(s) || 0) + 1);
        }
    }
    
    let res = [];
    for (let k of cnt.keys()) {
        res.push(k);
    }
    
    res.sort((a, b) => {
        if (cnt.get(a) == cnt.get(b)) return a < b ? -1 : a == b ? 0 : 1;
        else return cnt.get(a) - cnt.get(b);
    });
    return res;
};