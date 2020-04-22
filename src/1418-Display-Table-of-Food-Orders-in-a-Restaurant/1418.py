class Solution:
    def displayTable(self, orders: List[List[str]]) -> List[List[str]]:
        tf_cnt = collections.Counter([(T, F) for _, T, F in orders])
        foods  = sorted(set(F for _, _, F in orders))
        tables  = sorted(set(T for _, T, _ in orders), key=int)
        return   [["Table"] + foods] + [[T] + [str(tf_cnt[T, F]) for F in foods] for T in tables]