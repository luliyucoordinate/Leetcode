class FileSystem:
    def __init__(self):
        self.data = {"": -1}

    def create(self, path: str, value: int) -> bool:
        if path[:path.rfind("/")] not in self.data \
            or path in self.data:
            return False
        self.data[path] = value
        return True

    def get(self, path: str) -> int:
        return self.data.get(path, -1)