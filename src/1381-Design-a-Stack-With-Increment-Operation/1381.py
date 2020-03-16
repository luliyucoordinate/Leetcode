class CustomStack:

    def __init__(self, maxSize: int):
        self.c = maxSize
        self.s = []
        self.inc = []

    def push(self, x: int) -> None:
        if len(self.s) < self.c:
            self.s.append(x)
            self.inc.append(0)

    def pop(self) -> int:
        if not self.s: return -1
        if len(self.inc) > 1:
            self.inc[-2] += self.inc[-1]
        return self.s.pop() + self.inc.pop()

    def increment(self, k: int, val: int) -> None:
        if self.inc:
            self.inc[min(k, len(self.inc)) - 1] += val