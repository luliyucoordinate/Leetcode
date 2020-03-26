class Solution {
public:
    set<string> sstr;
    int kmp(string& t,int l)
    {
        vector<int> f(t.length()-l,0);
        int len = f.size();
        auto s = &t[l];
        int pos = 0;
        for(int i = 1; i<len; i++)
        {
            while(pos>0&&s[i]!=s[pos]) pos = f[pos-1];
            if(s[i]==s[pos])        pos++;
            f[i] = pos;
            if(pos==i){   
                if(pos%2)   sstr.insert(t.substr(l,(i+1)/2));
            } 
            else if(pos&&((i+1)%(i+1-pos)==0)){
                if(((i+1)/(i+1-pos))%2==0)  sstr.insert(t.substr(l,(i+1)/2));
            }
        }
        return (f[len-1]&&(len%(len-f[len-1])==0))?(len-f[len-1]):INT_MAX;
    }
    
    int distinctEchoSubstrings(string text) {
        int l = text.length()-1;
        for(int i = 0; i<=l; i++)   l = min(l,kmp(text,i));
        return sstr.size();
    }
};