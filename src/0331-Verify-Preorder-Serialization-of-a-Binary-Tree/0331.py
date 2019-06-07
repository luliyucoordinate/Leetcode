class Solution:
    def isValidSerialization(self, preorder: str) -> bool:
        nodes = preorder.split(",")
        dif = 1
        for node in nodes:
            dif -= 1
            if dif < 0:
                return False
            if node != "#":
                dif += 2
        return dif == 0