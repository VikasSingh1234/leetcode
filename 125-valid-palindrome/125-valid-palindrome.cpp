class Solution {
public:
    bool isPalindrome(string s) {
        int l=0;
        int r=s.length()-1;
        
        while(l<=r){
            if(s[l]==' '){
                l++;
                continue;
            }
            if(s[r]==' '){
                r--;
            }
            if(s[l]<='Z' && s[l]>='A'){
                s[l]+=32;
            }
            if(s[r]<='Z' && s[r]>='A'){
                s[r]+=32;
            }
            
            if((s[l]>=48 && s[l]<=57)||(s[l]>=97 && s[l]<=122)){
                if((s[r]>=48 && s[r]<=57)||(s[r]>=97 && s[r]<=122)){
                    if(s[l]==s[r]){
                        l++;
                        r--;
                    }
                    else{
                        return false;
                    }
                }
                else{
                    r--;
                }
            }
            else{
                l++;
            }
        }
        return true;
    }
};