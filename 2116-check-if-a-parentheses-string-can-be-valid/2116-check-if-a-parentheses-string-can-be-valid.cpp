class Solution {
public:
    bool canBeValid(string s, string locked) {
        
        int n = s.length();
        int change = 0;
        int open = 0;
        
        if(n%2){
            return false;
        }
        
        for(int i=0;i<n;i++){
            if(locked[i]=='0'){
                change++;
            }
            else{
                if(s[i]=='('){
                    open++;
                }
                else{
                    open--;
                }
                
                if(open==-1){
                    open = 0;
                    if(change){
                        change--;
                    }
                    else{
                        return false;
                    }
                }
            }
        }
        
        change =0;
        open =0;
        
        for(int i=n-1;i>=0;i--){
            if(locked[i]=='0'){
                change++;
            }
            else{
                if(s[i]==')'){
                    open++;
                }
                else{
                    open--;
                }
                
                if(open==-1){
                    open = 0;
                    if(change){
                        change--;
                    }
                    else{
                        return false;
                    }
                }
            }
        }
        return true;
    }
};