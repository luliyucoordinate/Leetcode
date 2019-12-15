class CombinationIterator:
    def __init__(self, ch: str, l: int):
        self.data = itertools.combinations(ch, l)
        self.last = ch[-l:]
        self.res = None

    def next(self) -> str:
        self.res = "".join(next(self.data))
        return self.res

    def hasNext(self) -> bool:
        return self.last != self.res