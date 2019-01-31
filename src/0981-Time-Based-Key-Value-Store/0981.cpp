#include <string>
#include <unordered_map>
#include <map>
using namespace std;

static int x = [](){std::ios::sync_with_stdio(false);cin.tie(0);return 0;}();
class TimeMap 
{
public:
    /** Initialize your data structure here. */
    TimeMap() {}
    
    void set(string key, string value, int timestamp) 
    {
        m[key].insert({timestamp, value});
    }
    
    string get(string key, int timestamp) 
    {
        auto it = m[key].upper_bound(timestamp);
        return it == m[key].begin() ? "" : prev(it)->second;
    }
private:
    unordered_map<string, map<int, string>> m;
};
