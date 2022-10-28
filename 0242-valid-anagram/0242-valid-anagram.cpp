class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> sh(26,0);
        vector<int> th(26,0);
        int n = s.length();
        if(n!=t.length())
            return false;
        
        for(int i=0;i<n;i++){
            sh[s[i]-'a']+=1;
            th[t[i]-'a']+=1;
        }
        
        for(int i=0;i<26;i++){
            if(sh[i]!=th[i])
                return false;
        }
        
        return true;
    }
};