class Solution:
    def distributeCandies(self, candies: int, num_people: int) -> List[int]:
        p = int(((8 * candies + 1)**0.5 - 1) // 2)
        R = candies - (p + 1) * p // 2
        r, c = p // num_people, p % num_people
        
        res = [0] * num_people
        for i in range(num_people):
            res[i] = (2 * (i + 1) + (r - 1) * num_people) * r // 2
            if i < c: res[i] += i + 1 + r * num_people       
        res[c] += R
        return res