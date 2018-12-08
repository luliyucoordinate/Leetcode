import collections
class Solution:
    def findSubstring(self, s, words):
        """
        :type s: str
        :type words: List[str]
        :rtype: List[int]
        """
        if not words:
            return []
        
        words_dict = collections.defaultdict(int)
        for word in words:
            words_dict[word] += 1
            
        s_len, words_len, word_len, res = len(s), len(words), len(words[0]), list()
        for k in range(word_len):
            has_words, num = collections.defaultdict(int), 0
            for i in range(k, s_len, word_len):
                word = s[i:i + word_len]
                if word in words_dict:
                    num += 1
                    has_words[word] += 1
                    while has_words[word] > words_dict[word]:
                        pos = i - word_len*(num - 1)
                        rem_word = s[pos:pos + word_len]
                        has_words[rem_word] -= 1
                        num -= 1
                else:
                    has_words.clear()
                    num = 0
                    
                if num == words_len:
                    res.append(i - word_len*(num - 1))
        return res

if __name__ == "__main__":
    s = "barfoofoobarthefoobarman"
    words = ["bar","foo","the"]
    print(Solution().findSubstring(s, words))