class Solution:
    def entityParser(self, text: str) -> str:
        res = []
        n, i = len(text), 0
        entity = {
            '&quot': '\"',
            '&apos': "'",
            '&gt': '>',
            '&lt': '<',
            '&frasl': '/', 
            '&amp': '&',
        }
        
        while i < n:
            if text[i] == '&':
                t = ''
                while text[i] != ';':
                    t += text[i]
                    i += 1
                if t in entity:
                    res.append(entity[t])
                else:
                    res.append(t + ";")
            else:
                res.append(text[i])
            i += 1
        return "".join(res)