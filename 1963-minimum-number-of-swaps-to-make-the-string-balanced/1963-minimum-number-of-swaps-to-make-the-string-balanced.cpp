class Solution {
public:
    int minSwaps(string s) {
        stack<char> st;
        
        for(int i=0;i<s.length();i++){
            if(s[i]=='['){
                st.push(s[i]);
            }
            else{
                if(!st.empty() && st.top()=='['){
                    st.pop();
                }
                else{
                    st.push(s[i]);
                }
            }
        }
        
        float open=0,close=0;
        while(!st.empty()){
            if(st.top()=='['){
                open++;
            }
            else{
                close++;
            }
            
            st.pop();
        }
        
        if(open>=close){
            return (open-close)/2 + ceil(open/2);
        }
        else{
            return (close-open)/2 + ceil(close/2);
        }
    }
};