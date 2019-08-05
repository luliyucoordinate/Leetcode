class SnapshotArray:
    def __init__(self, length: int):
        self.dif = {}
        self.snaps = []

    def set(self, index: int, val: int) -> None:
        self.dif[index] = val

    def snap(self) -> int:
        self.snaps.append(self.dif.copy())
        return len(self.snaps) - 1

    def get(self, index: int, snap_id: int) -> int:
        return self.snaps[snap_id][index] if index in self.snaps[snap_id] else 0