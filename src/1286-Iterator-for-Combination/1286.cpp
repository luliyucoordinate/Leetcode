class CombinationIterator 
{
public:
    CombinationIterator(string ch, int l) 
    {
        combine(0, l, "", ch);
    }
    
    string next() 
    {
        string res = q.front();
        q.pop();
        return res;
    }
    
    bool hasNext() 
    {
        return !q.empty();
    }
private:
    queue<string> q;
    
    void combine(int s, int k, string cur, string& ch)
    {
        if (cur.size() == k) {
            q.push(cur);
            return;
        }
        
        for (int i = s; i <= ch.size() - (k - cur.size()); i++)
        {
            combine(i + 1, k, cur + ch[i], ch);
        }
    }
};