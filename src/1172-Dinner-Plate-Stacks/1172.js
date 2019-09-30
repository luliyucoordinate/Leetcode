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
 * @param {number} capacity
 */
var DinnerPlates = function(capacity) {
    this.q = new PriorityQueue((a, b) => a < b);
    this.n = capacity;
    this.stacks = [];
    this.stacks_len = 0;
};

/** 
 * @param {number} val
 * @return {void}
 */
DinnerPlates.prototype.push = function(val) {
    while (!this.q.isEmpty() && this.q.peek() < this.stacks_len && this.stacks[this.q.peek()].length == this.n) {
        this.q.pop();
    }
    if (this.q.isEmpty()) this.q.push(this.stacks_len);

    if (this.q.peek() == this.stacks_len) {
        this.stacks.push(new Array());
        this.stacks_len++;
    }
    this.stacks[this.q.peek()].push(val);
};

/**
 * @return {number}
 */
DinnerPlates.prototype.pop = function() {
    while (this.stacks_len > 0 && this.stacks[this.stacks_len - 1].length == 0) {
        this.stacks.pop();
        this.stacks_len--;
    }
    return this.popAtStack(this.stacks_len - 1);
};

/** 
 * @param {number} index
 * @return {number}
 */
DinnerPlates.prototype.popAtStack = function(index) {
    if (index >= 0 && index < this.stacks_len && this.stacks[index].length > 0) {
        let ret = this.stacks[index].pop();
        this.q.push(index);
        return ret;
    }
    return -1;
};