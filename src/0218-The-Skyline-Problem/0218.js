const t = 0;
const parent = i => ((i + 1) >>> 1) - 1;
const left = i => (i << 1) + 1;
const right = i => (i + 1) << 1;

class PriorityQueue {
    constructor(comparator = (a, b) => a > b) {
        this._heap = [];
        this._comparator = comparator;
    }

    size() {
        return this._heap.length;
    }

    isEmpty() {
        return this.size() == 0;
    }

    peek() {
        return this._heap[t];
    }

    push(...values) {
        values.forEach(value => {
            this._heap.push(value);
            this._siftUp();
        });
        return this.size();
    }

    pop() {
        const poppedValue = this.peek();
        const bottom = this.size() - 1;
        if (bottom > t) {
            this._swap(t, bottom);
        }
        this._heap.pop();
        this._siftDown();
        return poppedValue;
    }

    replace(value) {
        const replacedValue = this.peek();
        this._heap[t] = value;
        this._siftDown();
        return replacedValue;
    }

    _greater(i, j) {
        return this._comparator(this._heap[i], this._heap[j]);
    }

    _swap(i, j) {
        [this._heap[i], this._heap[j]] = [this._heap[j], this._heap[i]];
    }

    _siftUp() {
        let node = this.size() - 1;
        while (node > t && this._greater(node, parent(node))) {
            this._swap(node, parent(node));
            node = parent(node);
        }
    }

    _siftDown() {
        let node = t;
        while (
            (left(node) < this.size() && this._greater(left(node), node)) ||
            (right(node) < this.size() && this._greater(right(node), node))
        ) {
            let maxChild = (right(node) < this.size() && this._greater(right(node), left(node))) ? right(node) : left(node);
            this._swap(node, maxChild);
            node = maxChild;
        }
    }
}
/**
 * @param {number[][]} buildings
 * @return {number[][]}
 */
var getSkyline = function(buildings) {
    let points = [], rSet = new Set();
    for (let it of buildings) {
        points.push([it[0], -it[2], it[1]]);
        if (!rSet.has(it[1])) {
            points.push([it[1], 0, 0])
            rSet.add(it[1]);
        }
    }
    let cmp = (a, b) => {
        if (a[0] == b[0]) return a[1] - b[1];
        return a[0] - b[0];
    }
    points.sort(cmp);
    const q = new PriorityQueue(cmp);
    q.push([0, Number.MAX_VALUE])
    let res = [[0, 0]];
    for (let it of points) {
        while (q.peek()[1] <= it[0]) q.pop();
        if (it[1] != 0) q.push([it[1], it[2]]);
        if (res[res.length-1][1] != -q.peek()[0])
            res.push([it[0], -q.peek()[0]]);
    }
    res.shift();
    return res;
};