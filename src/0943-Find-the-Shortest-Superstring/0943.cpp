#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

static int x = []() {std::ios::sync_with_stdio(false); cin.tie(0); return 0; }();
class Solution 
{
    const short validMask[12] = {0x1,0x2,0x4,0x8,0x10,0x20,0x40,0x80,0x100,0x200,0x400,0x800};
        
    class MyNode;
    vector<MyNode> nodes;
    
    class MyNode {
    public:
        MyNode(short i, short N, string s):idx(i),min(0x3FFF),str(s){edges.resize(N,-1);}
        short idx;
        short min;
        vector<short> edges;
        string str;
    };
    
    class MyState {
    public:
        MyState(short c, short d, short v, MyState* p):cur(c),dis(d),valid(v),prevState(p){}
        short cur;
        short dis;
        short valid;
        MyState* prevState;
        void print() {cout << cur << " " << dis << " " << valid << endl;}
    };
    
    struct MyStateCmp {
        bool operator()(const MyState* a, const MyState* b) {
            return a->dis > b->dis;
        }
    };
    
    string shortestSuperstring(vector<string>& A) 
    {        
        int N = A.size();
        short validFull = (1<<N)-1;
        
        nodes.clear();
        for (int i = 0; i < N; ++i) nodes.push_back(MyNode(i,N,A[i]));
        
        for (int i = 0; i < N; ++i) 
        {
            MyNode& curNode = nodes[i];
            const string & lStr = A[i];
            for (int j = 0; j < N; ++j) 
            {
                if (i == j) continue;
                MyNode& nextNode = nodes[j];
                const string & rStr = A[j];
                int maxOverlap = min(lStr.size(),rStr.size());
                for (int k = maxOverlap; k >= 0; --k) 
                {
                    bool flag = true;
                    for (int l = 0; l < k; ++l) 
                    {
                        if (lStr[lStr.size()-k+l] != rStr[l]) 
                        {
                            flag = false;
                            break;
                        }
                    }
                    if (flag) 
                    {
                        curNode.edges[j] = rStr.size()-k;
                        if (curNode.edges[j] < nextNode.min) 
                        {
                            nextNode.min = curNode.edges[j];
                        }
                        break;
                    }
                }
            }
        }

        for (int i = 0; i < N; ++i) 
        {
            MyNode& curNode = nodes[i];
            for (int j = 0; j < N; ++j) 
            {
                if (i == j) continue;
                MyNode& nextNode = nodes[j];
                curNode.edges[j] -= nextNode.min;
            }
        }
        priority_queue<MyState*,vector<MyState*>,MyStateCmp> pq;
        
        for (int i = 0; i < N; ++i) 
        {
            pq.push(new MyState(i,A[i].size()-nodes[i].min,validFull^validMask[i],NULL));
        }
        
        int count = 0;
        while (!pq.empty()) 
        {
            MyState* curState = pq.top(); pq.pop(); ++count;
            if (curState->valid == 0) 
            {
                stack<short> btS;
                while(curState!=NULL) { btS.push(curState->cur); curState=curState->prevState; }
                
                string ret = A[btS.top()];
                while (!btS.empty()) 
                {
                    short curI = btS.top(); btS.pop(); 
                    if (btS.empty()) break;
                    short nextI = btS.top();  
                    ret += A[nextI].substr(A[nextI].size()-nodes[curI].edges[nextI]-nodes[nextI].min);
                }
                return ret;
            } 
            else 
            {
                for (int i = 0; i < N; ++i) 
                {
                    if (curState->valid & validMask[i]) 
                    {
                        short nextDis = curState->dis + nodes[curState->cur].edges[i];
                        pq.push(new MyState(i,nextDis,curState->valid^validMask[i],curState));
                    }
                }
            }
        }
        return "";
    }
};
int main()
{
    string A = {"catg","ctaagt","gcta","ttca","atgcatc"};
    cout << Solution().shortestSuperstring(A);
    return 0;
}
