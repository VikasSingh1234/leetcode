class Solution {
public:
    string makeGood(string s) {
        stack<char> st;
        string ans;
        int n = s.length();
        int i = 1;
        
        st.push(s[0]);
        
        while(i<n){
            if(!st.empty()){
                char t = st.top();
                if(abs(int(s[i]-t))==32){
                    st.pop();
                }
                else{
                    st.push(s[i]);
                }
            }
            else{
                st.push(s[i]);
            }
            i++;
        }
        
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        
        return ans;
    }
};