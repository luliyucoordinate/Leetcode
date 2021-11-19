class Solution:
    def flipAndInvertImage(self, image: List[List[int]]) -> List[List[int]]:
        arr = list()
        for row in image:
            arr.append(row[::-1])
            for i in range(len(arr[-1])):
                if arr[-1][i] == 0:
                    arr[-1][i] = 1
                else:
                    arr[-1][i] = 0
        return arr
