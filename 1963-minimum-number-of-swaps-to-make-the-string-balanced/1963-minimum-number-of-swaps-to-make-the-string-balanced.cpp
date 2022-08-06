class Solution {
public:
    int minSwaps(string s) {
        stack<char> st;
        float open=0,close=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='['){
                st.push(s[i]);
                open++;
            }
            else{
                if(!st.empty() && st.top()=='['){
                    st.pop();
                    open--;
                }
                else{
                    st.push(s[i]);
                    close++;
                }
            }
        }
        
//         float open=0,close=0;
//         while(!st.empty()){
//             if(st.top()=='['){
//                 open++;
//             }
//             else{
//                 close++;
//             }
            
//             st.pop();
//         }
        
        if(open>=close){
            return (open-close)/2 + ceil(open/2);
        }
        else{
            return (close-open)/2 + ceil(close/2);
        }
    }
};