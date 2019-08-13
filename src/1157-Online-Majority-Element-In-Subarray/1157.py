class MajorityChecker:
    def __init__(self, arr: List[int]):
        self.data = arr
        self.indexs = collections.defaultdict(list)
        for i, v in enumerate(arr):
            self.indexs[v].append(i)
        self.tree = [[0, 0] for _ in range(4*len(arr))]
        if self.data:
            self.buildSegmentTree(0, 0, len(arr) - 1)
            
    def buildSegmentTree(self, treeIndex, l, r):
        if l == r:
            self.tree[treeIndex][0] = self.data[l]
            self.tree[treeIndex][1] = 1
            return 
        
        lc, rc = 2 * treeIndex + 1, 2 * (treeIndex + 1)
        mid = l + r >> 1
        self.buildSegmentTree(lc, l, mid)
        self.buildSegmentTree(rc, mid + 1, r)
        if self.tree[lc][0] == self.tree[rc][0]:
            self.tree[treeIndex][0] = self.tree[lc][0]
            self.tree[treeIndex][1] = self.tree[rc][1] + self.tree[lc][1]
        elif self.tree[lc][1] < self.tree[rc][1]:
            self.tree[treeIndex][0] = self.tree[rc][0]
            self.tree[treeIndex][1] = self.tree[rc][1] - self.tree[lc][1]
        else:
            self.tree[treeIndex][0] = self.tree[lc][0]
            self.tree[treeIndex][1] = self.tree[lc][1] - self.tree[rc][1]

    def query(self, left: int, right: int, threshold: int) -> int:
        res = self._query(0, 0, len(self.data)-1, left, right)[0]
        
        if bisect.bisect_right(self.indexs[res], right) - bisect.bisect_left(self.indexs[res], left) < threshold:
            return -1
        return res
        
    def _query(self, treeIndex, l1, r1, l2, r2):
        if l1 == l2 and r1 == r2:
            return self.tree[treeIndex]
        mid = l1 + r1 >> 1
        lc, rc = 2 * treeIndex + 1, 2 * (treeIndex + 1)
        if r2 <= mid:
            return self._query(lc, l1, mid, l2, r2)
        if l2 > mid:
            return self._query(rc, mid + 1, r1, l2, r2)
        l, r = self._query(lc, l1, mid, l2, mid), self._query(rc, mid + 1, r1, mid + 1, r2)
        
        res = [0, 0]
        if l[0] == r[0]:
            res[0] = l[0]
            res[1] = l[1] + r[1]
        elif l[1] < r[1]:
            res[0] = r[0]
            res[1] = r[1] - l[1]
        else:
            res[0] = l[0]
            res[1] = l[1] - r[1]
        return res