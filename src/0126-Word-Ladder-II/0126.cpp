class Solution 
{
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string> &wordList) 
    {
        int step = 2;
        vector<vector<string>> res;
        unordered_set<string> wordDict(wordList.begin(), wordList.end());
        if (wordDict.count(endWord) == 0) return res;
        unordered_map<string, vector<vector<string>>> s1, s2, stack;
        s1[beginWord] = {{beginWord}};
        s2[endWord] = {{endWord}};

        while (!s1.empty())
        {
            stack.clear();
            for (auto s : s1) wordDict.erase(s.first);
            for (auto s : s1)
            {
                for (int i = 0; i < beginWord.size(); ++i)
                {
                    for (char c = 'a'; c <= 'z'; ++c)
                    {
                        string tmp = s.first;
                        tmp[i] = c;
                        if (!wordDict.count(tmp)) continue;
                        if (s2.count(tmp)) 
                        {
                            if (s.second[0][0] == beginWord)
                            {
                                for (auto& f : s.second)
                                {
                                    for (auto& v : s2[tmp])
                                    {
                                        vector<string> tp = f;
                                        tp.insert(tp.end(), v.rbegin(), v.rend());
                                        res.emplace_back(tp);
                                    }
                                }
                            }
                            else
                            {
                                for (auto& f : s.second)
                                {
                                    for (auto& v : s2[tmp])
                                    {
                                        vector<string> tp = v;
                                        tp.insert(tp.end(), f.rbegin(), f.rend());
                                        res.emplace_back(tp);
                                    }
                                }
                            }
                        }
                        for (auto& p : s.second) 
                        {
                            vector<string> tp = p;
                            tp.push_back(tmp);
                            stack[tmp].emplace_back(tp);
                        }
                    }
                }  
            }   
            s1 = stack.size() < s2.size() ? stack : s2;
            s2 = stack.size() < s2.size() ? s2 : stack;
            ++step;
            if (!res.empty() and step > res[0].size()) return res;
        }
        return res;
    }
};