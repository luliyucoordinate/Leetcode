import heapq
class DinnerPlates:
    def __init__(self, capacity: int):
        self.data = []
        self.q = []
        self.n = capacity

    def push(self, val: int) -> None:
        while self.q and len(self.data[self.q[0]]) == self.n:
            heapq.heappop(self.q)
        if not self.q:
            heapq.heappush(self.q, len(self.data))
            self.data.append([])
        self.data[self.q[0]].append(val)

    def pop(self) -> int:
        while self.data and not self.data[-1]:
            self.data.pop()
        return self.popAtStack(len(self.data) - 1)

    def popAtStack(self, index: int) -> int:
        if 0 <= index < len(self.data) and self.data[index]:
            heapq.heappush(self.q, index)
            return self.data[index].pop()
        return -1