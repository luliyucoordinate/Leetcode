/**
 * @param {character[][]} board
 * @param {string[]} words
 * @return {string[]}
 */
var findWords = function(board, words) {
    let dire =[[-1, 0], [1, 0], [0, -1], [0, 1]], res = [];
    let r = board.length, c = board[0].length;
    
    let root = {};
    for (let i in words) {
        let node = root;
        for (let ch of words[i]) {
            if (!node[ch]) 
                node[ch] = {};
            node = node[ch];
        }
        node.wordId = i;
    }
    
    let dfs = function(i, j, node) {
        if (i < 0 || i >= r ||j <0 || j >= c || !node[board[i][j]]) return ;
        let tmp = board[i][j];
        board[i][j] = '$';
        node = node[tmp];
        let nid = Number(node.wordId);
        if (!isNaN(nid) && nid != -1) {
            res.push(words[nid]);
            node.wordId = -1;
        }
        
        for (let it of dire) {
            let nx = it[0] + i, ny = it[1] + j;
            dfs(nx, ny, node);
        }
        board[i][j] = tmp;
    }
    
    for (let i = 0; i < r; i++) {
        for (let j = 0; j < c; j++) {
            dfs(i, j, root);
        }
    }
    return res;
};