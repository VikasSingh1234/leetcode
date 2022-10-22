class Solution {
public:
    int countGoodSubstrings(string s) {
        if(s.length()<=2){
            return 0;
        }
        
        int res = 0;
        for(int i=2;i<s.length();i++){
            if(s[i]!=s[i-1] && s[i-1]!=s[i-2] && s[i]!=s[i-2]){
                res++;
            }
        }
        return res;
    }
};