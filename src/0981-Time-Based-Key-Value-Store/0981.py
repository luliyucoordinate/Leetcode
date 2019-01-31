import collections
import bisect
class TimeMap:
    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.data = collections.defaultdict(list)

    def set(self, key: 'str', value: 'str', timestamp: 'int') -> 'None':
        self.data[key].append((timestamp, value))

    def get(self, key: 'str', timestamp: 'int') -> 'str':
        if key not in self.data:
            return ''
        idx = bisect.bisect_right(self.data[key], (timestamp, 'z'*101))
        return '' if idx == 0 else self.data[key][idx-1][1]