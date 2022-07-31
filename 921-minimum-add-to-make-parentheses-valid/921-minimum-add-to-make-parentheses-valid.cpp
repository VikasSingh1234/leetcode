class Solution {
public:
    int minAddToMakeValid(string s) {
        int left=0,right=0;
        int n = s.length();
    
        for(int i=0;i<n;i++){
            if(s[i]==')'){
                if(left>0){
                    left--;
                }
                else{
                    right++;
                }
            }
            else{
                left++;
            }
        }
        return (left+right);
    }
};