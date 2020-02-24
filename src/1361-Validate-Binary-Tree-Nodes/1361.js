/**
 * @param {number} n
 * @param {number[]} leftChild
 * @param {number[]} rightChild
 * @return {boolean}
 */
var validateBinaryTreeNodes = function(n, leftChild, rightChild) {
    let d = Array(n).fill(0);
    for (let i of leftChild) if (i != -1) d[i]++;
    for (let i of rightChild) if (i != -1) d[i]++;

    let root = -1;
    for (let i = 0; i < n; i++) {
        if (d[i] == 0) {
            if (root != -1) return false;
            root = i;
        }
    }
    if (root == -1) return false;

    let vis = new Map(), q = [root];
    vis.set(root, 1);
    while (q.length > 0) {
        let pre = q.shift();
        if (leftChild[pre] != -1) {
            if (vis.has(leftChild[pre])) return false;
            vis.set(leftChild[pre], 1);
            q.push(leftChild[pre]);
        }
        if (rightChild[pre] != -1) {
            if (vis.has(rightChild[pre])) return false;
            vis.set(rightChild[pre], 1);
            q.push(rightChild[pre]);
        }
    }
    return vis.size == n;
};