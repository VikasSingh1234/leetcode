class Solution {
public:
    bool pattern(string str1, string str2){
        int n = str2.length();
        int m = str1.length();
        for(int i=0;i<m;i++){
            if(str1[i]!=str2[i%n]){
                return false;
            }
        }
        
        return true;
    }
    string gcdOfStrings(string str1, string str2) {
        int n = str2.length();
        int m = str1.length();
        int len = min(n,m);
        int ans = -1;
        for(int i=1;i<=len;i++){
            if(n%i==0 && m%i==0){
                //cout<<i<<" "<<str1.substr(0,i)<<endl;
                if(pattern(str1,str1.substr(0,i))&& pattern(str2,str1.substr(0,i))){
                    ans = i;
                }
            }
        }
        
        if(ans==-1) return "";
        
        return str1.substr(0,ans);
            
    }
};