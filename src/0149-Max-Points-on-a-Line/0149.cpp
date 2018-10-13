#include <iostream>
#include <vector>
#include <unordered_map>
#include <climits>
#include <map>
using namespace std;


 //Definition for a point.
struct Point {
    int x;
    int y;
    Point() : x(0), y(0) {}
    Point(int a, int b) : x(a), y(b) {}
};

static int x = []() {std::ios::sync_with_stdio(false); cin.tie(0); return 0; }();
class Solution 
{
public:
    int maxPoints(vector<Point> &points) 
    {       
        if(points.size() < 2) return points.size();     
        int result = 0;   
        map<pair<int, int>, int> lines; 
        for(unsigned int i = 0; i < points.size(); i++) {    
            lines.clear();
            int duplicate = 1, vertical = 1;           
            for(unsigned int j = i + 1; j < points.size(); j++) 
            {                
                if(points[j].x == points[i].x && points[j].y == points[i].y) 
                {                    
                    duplicate++;
                    continue;
                }
                else if(points[j].x == points[i].x) vertical++;
                else 
                {    
                    int a = points[j].x - points[i].x;
                    int b = points[j].y - points[i].y;
                    int gcd = GCD(a, b);
                    a /= gcd; b /= gcd;
                    lines[make_pair(a, b)]++;
                }
            }  
            if (result < duplicate) result = duplicate;
            if (result < vertical) result = vertical;
            for (auto& line : lines)
            {
                int tmp = duplicate + line.second;
                if (result < tmp) result = tmp;
            }      
        }        
        return result;
    }
private:
    int GCD(int a, int b) 
    {      
        if(b == 0) return a;
        else return GCD(b, a % b);
    }
};
int main()
{
    return 0;
}