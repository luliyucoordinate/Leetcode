#include <iostream>
#include <queue>
using namespace std;

static int x = []() {std::ios::sync_with_stdio(false); cin.tie(0); return 0; }();
class RecentCounter 
{
public:
    RecentCounter() {}
    
    int ping(int t) 
    {
        pings.push(t);
        while (!pings.empty() and pings.front() < t - 3000) pings.pop();
        return pings.size();
    }
private:
    queue<int> pings;
};

int main()
{
    return 0;
}
