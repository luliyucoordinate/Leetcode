class Solution:
    def distributeCandies(self, candies: int, num_people: int) -> List[int]:
        res = [0] * num_people
        step = 0
        while candies > 0:
            res[step % num_people] += min(candies, step + 1)
            step += 1
            candies -= step
        return res