static int x = []() {std::ios::sync_with_stdio(false); cin.tie(0); return 0; }();

class Node 
{
public:
    Node()  : isWord(false){}
    ~Node()
    {
        for (const auto& item : next) delete item.second; 
    }

    bool isWord;
    unordered_map<char, Node*> next;
};

class Trie 
{
public:
    /** Initialize your data structure here. */
    Trie()  : _root(new Node()) {}
    ~Trie() { delete _root; }
    
    /** Inserts a word into the trie. */
    void insert(string word) 
    {
        auto cur = _root;
        for (auto c : word)
        {
            if (!(cur->next).count(c)) // or if (cur->next[c] == nullptr)
                cur->next[c] = new Node();   
            cur = cur->next[c];
        }
        if (!cur->isWord) cur->isWord = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) 
    {
        auto cur = _search(word);
        return cur != nullptr and cur->isWord;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) 
    {
        return _search(prefix) != nullptr;
    }
private:
    Node* _root;
    
    Node* _search(string word)
    {
        auto cur = _root;
        for (auto c : word)
        {
            if (!cur->next.count(c)) return nullptr;
            cur = cur->next[c];
        }
        return cur;
    }
};