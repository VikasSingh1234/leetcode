class Solution {
public:
    vector<int> prefix(string s){
            int n = s.length();
            vector<int> res(n,0);
            
            for(int i=1;i<s.length();i++){
                int j = res[i-1];
                
                while(j>0 && s[i]!=s[j]){
                    j = res[j-1];
                }
                
                if(s[i]==s[j]){
                    j++;
                }
                res[i] = j;
            }
            return res;
        }
    
    int strStr(string haystack, string needle) {
        vector<int> p = prefix(needle);
        int i=0,j=0;
        
        while(i<haystack.length()){
            if(haystack[i]==needle[j]){
                i++;
                j++;
            }
            else{
                if(j!=0){
                    j = p[j-1];
                }
                else{
                    i++;
                }
            }
            
            if(j==needle.length()){
                return (i-j);
            }
        }
        return -1;
    }
};