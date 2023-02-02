class Solution {
public:
    
    bool check(string s1,string s2,unordered_map<char,int> mpp){
        int n = s1.length();
        int m = s2.length();
        int len = min(n,m);
        
        for(int i=0;i<len;i++){
            if(mpp[s1[i]]==mpp[s2[i]])
                continue;
            else if(mpp[s1[i]] < mpp[s2[i]])
                return true;
            else return false;
                
        }
        
        if(n>m)
            return false;
        return true;
    }
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char,int> mpp;
        int n = words.size();
        for(int i=0;i<26;i++){
            mpp[order[i]] = i;
        }
        
        for(int i=1;i<n;i++){
            if(check(words[i-1],words[i],mpp)==false){
                return false;
            }
        }
        
        return true;
    }
};