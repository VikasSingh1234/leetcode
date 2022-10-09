class Solution {
public:
    string robotWithString(string s) {
        
        string p,t;
        vector<int> words(26,0);
        int minidx = 0;
        
        for(int i=0;i<s.length();i++){
            words[s[i]-'a']++;
        }
        
        for(int i=0;i<s.length();i++){
            t+=s[i];
            words[s[i]-'a']--;
            
            while(minidx<26 && words[minidx]==0){
                ++minidx;
            }
            
            while(!t.empty() && (t.back()-'a')<=minidx){
                p+=t.back();
                t.pop_back();
            }
        }
        return p;
    }
};