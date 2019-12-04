var tictactoe = function(moves) {
    let score = new Array(2), p = 0;
    for (let i = 0; i < 2; i++) {
        score[i] = new Array(8);
        score[i].fill(0);
    }

    for (let it of moves) {
        score[p][it[0]]++; score[p][it[1] + 3]++;
        score[p][6] += (it[0] == it[1] ? 1 : 0);
        score[p][7] += (it[0] + it[1] == 2 ? 1 : 0);
        for (let x of score[p])
            if (x == 3) return p == 0 ? "A" : "B";
        p ^= 1;
    }
    return moves.length == 9 ? "Draw" : "Pending";
};