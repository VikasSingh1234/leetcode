class Solution {
public:
    int myAtoi(string s) {
        string ans;
        long int res=0;
        for(int i=0;i<s.length();i++){
            if(ans.length()==0 && (s[i]=='+' || s[i]=='-')){
                ans.push_back(s[i]);
            }
            else if(ans.length()==0 && s[i]==' '){
                continue;
            }
            else{
                long int prev = res;
                if(s[i]>=48 && s[i]<=57){
                    ans.push_back(s[i]);
                    res = stol(ans);
                    if(res<INT_MIN ){
                        return INT_MIN;
                    }
                    if(res>INT_MAX){
                        return INT_MAX;
                    }
                }
                else{
                    return prev;
                }
            }
            
        }
        return res;
    }
};