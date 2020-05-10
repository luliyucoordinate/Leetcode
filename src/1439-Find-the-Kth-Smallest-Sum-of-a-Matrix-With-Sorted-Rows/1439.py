class Solution:
    def kthSmallest(self, mat: List[List[int]], k: int) -> int:
        def ordered_sums(rows):
            if len(rows) == 1:
                yield from rows[0]
            else:
                first, rest = rows[0], rows[1:]
                teed = itertools.tee(ordered_sums(rest), len(first))
                yield from heapq.merge(*(
                    map(val.__add__, sums)
                    for val, sums in zip(first, teed)
                ))
            
        return next(itertools.islice(ordered_sums(mat), k - 1, None))