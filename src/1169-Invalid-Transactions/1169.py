class Solution:
    def invalidTransactions(self, transactions: List[str]) -> List[str]:
        data, delt = collections.defaultdict(list), set()
        for i, tran in enumerate(transactions):
            name, time, amount, city = tran.split(",")
            if int(amount) > 1000:
                delt.add(i)
            data[name].append([int(time), city, i])
            
        for it in data:
            data[it].sort()
            q = []
            for t1, c1, i1 in data[it]:
                while q and q[0][0] < t1 - 60:
                    q.pop(0)
                for t2, c2, i2 in q:
                    if c1 != c2:
                        delt.add(i2)
                        delt.add(i1)
                q.append([t1, c1, i1])
        return [transactions[i] for i in delt]