class Solution:
    def fullJustify(self, words, maxWidth):
        """
        :type words: List[str]
        :type maxWidth: int
        :rtype: List[str]
        """
        if not words:
            return list()
        
        res, row = list(), list()
        words_len, count = len(words), 0
        i = 0
        while i < words_len:
            if len(words[i]) + count <= maxWidth:
                count += len(words[i]) + 1
                row.append(words[i])
                i += 1
                continue
            else:
                if len(row) == 1:
                    res.append(str(row[0])+' '*(maxWidth - len(row[0])))
                else:
                    extraSpace = maxWidth - count + len(row)
                    num_space = extraSpace//(len(row) - 1)
                    pre_space = extraSpace%(len(row) - 1)
                    tmp = ''
                    for word in row[:-1]:
                        if pre_space > 0:
                            tmp += str(word) + ' '*(num_space + 1)
                            pre_space -= 1
                        else:
                            tmp += str(word) + ' '*(num_space + 0)
                            
                    tmp += str(row[-1])
                    res.append(tmp)
                    
                row.clear()
                count = 0
                
        tmp = ' '.join(row)  
        res.append(tmp + (maxWidth - len(tmp))*' ')
        return res

if __name__ == "__main__":
    words = ["What","must","be","acknowledgment","shall","be"]
    maxWidth = 16
    print(Solution().fullJustify(words, maxWidth))