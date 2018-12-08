from collections import deque
class Solution:
    def deckRevealedIncreasing(self, deck):
        """
        :type deck: List[int]
        :rtype: List[int]
        """
        res = deque()
        deck.sort(reverse=True)
        for card in deck:
            res.rotate()
            res.appendleft(card)
            
        return list(res) 