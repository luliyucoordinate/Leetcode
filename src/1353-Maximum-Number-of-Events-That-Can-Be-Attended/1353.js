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

var maxEvents = function(events) {
    events.sort((a, b) => a[0] - b[0]);
    const q = new PriorityQueue((a, b) => a < b);
    let res = 0, index = 0, n = events.length;
        
    let l = 100000, r = 0;
    for (let it of events) {
        l = Math.min(it[0], l);
        r = Math.max(it[1], r);
    }

    for (let i = l; i <= r; i++) {
        while (index < n && events[index][0] <= i) {
            q.push(events[index][1]);
            index++;
        }

        if (q.isEmpty() && index == n) return res;

        while (!q.isEmpty()) {
            let pre = q.pop();
            if (i <= pre) {
                res++;
                break;
            }
        }
    }
    return res;
};