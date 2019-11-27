class Solution:
    def suggestedProducts(self, products: List[str], searchWord: str) -> List[List[str]]:
        products.sort()
        l, r, res = 0, len(products) - 1, []
        for i, c in enumerate(searchWord):
            l = bisect.bisect_left(products, searchWord[:i+1], l, r + 1)
            while l <= r and (len(products[r]) <= i or products[r][i] != c):
                r -= 1
            res.append(products[l:min(l + 3, r + 1)] if l <= r else [])
        return res