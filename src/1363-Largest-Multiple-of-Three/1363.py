class Solution:
    def largestMultipleOfThree(self, digits: List[int]) -> str:
        cnt = [0] * 10
        for i in digits: cnt[i] += 1
            
        b1, b2 = cnt[1] + cnt[4] + cnt[7], cnt[2] + cnt[5] + cnt[8]
        t = (b1 + b2 * 2) % 3
        
        if t == 1:
            if b1 >= 1: b1 -= 1
            else: b2 -= 2
        elif t == 2:
            if b2 >= 1: b2 -= 1
            else: b1 -= 2
                
        res = ""
        for i in range(9, -1, -1):
            if i % 3 == 0:
                while cnt[i]:
                    res += str(i)
                    cnt[i] -= 1
            elif i % 3 == 1 and b1:
                while cnt[i] and b1:
                    res += str(i)
                    cnt[i] -= 1
                    b1 -= 1
            else:
                while cnt[i] and b2:
                    res += str(i)
                    cnt[i] -= 1
                    b2 -= 1
        
        if res and res[0] == "0": return "0"
        return res