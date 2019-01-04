static int x = []() {std::ios::sync_with_stdio(false); cin.tie(0); return 0; }();
class LRUCache 
{
public:
    LRUCache(int capacity) : capacity(capacity) {}
    
    int get(int key) 
    {
        if (cache.find(key) == cache.end()) return -1;
        li.splice(li.begin(), li, cache[key]);
        return cache[key]->second;
    }
    
    void put(int key, int value) 
    {
        if (get(key) != -1) 
        {
            cache[key]->second = value;
            return;
        }
        
        if (cache.size() == capacity) 
        {
            int delKey = li.back().first;
            li.pop_back();
            cache.erase(delKey);
        }
        
        li.emplace_front(key, value);
        cache[key] = li.begin();
    }
private:
    int capacity;
    list<pair<int, int>> li;
    unordered_map<int, list<pair<int, int>>::iterator> cache;
};