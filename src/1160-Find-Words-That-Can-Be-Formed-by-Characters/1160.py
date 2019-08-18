class Solution:
    def countCharacters(self, words: List[str], chars: str) -> int:
        return len(''.join(filter(lambda x : len(collections.Counter(x) - collections.Counter(chars)) == 0, words)))