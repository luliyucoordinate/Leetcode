var Leaderboard = function() {
    this.d = {};
};

/** 
 * @param {number} playerId 
 * @param {number} score
 * @return {void}
 */
Leaderboard.prototype.addScore = function(playerId, score) {
    if (playerId in this.d) {
        this.d[playerId] += score;
    } else this.d[playerId] = score;
};

/** 
 * @param {number} K
 * @return {number}
 */
Leaderboard.prototype.top = function(K) {
    let q = []
    for (let i in this.d) {
        q.push(this.d[i]);
    }
    q.sort((a, b) => b - a);
    let res = 0;
    while (K) {
        res += q[--K];
    }
    return res;
};

/** 
 * @param {number} playerId
 * @return {void}
 */
Leaderboard.prototype.reset = function(playerId) {
    delete this.d[playerId];
};