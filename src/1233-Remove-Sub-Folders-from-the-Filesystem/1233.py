class Solution:
    def removeSubfolders(self, folder: List[str]) -> List[str]:
        folder.sort()
        res, l, parent = [], 2, '' 
        for f in folder:
            if f[:l] != parent:
                l, parent = len(f) + 1, f + '/'
                res.append(f)   
        return res